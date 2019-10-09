#include <iostream>
#include <string>

#include "../headers/word.hpp"
#include "../headers/thread_manager.hpp"

// THREADS :
#include <pthread.h>


/*
    Le main sait où se situe la valeur à chercher maximum,
    Du coup une fois qu'un thread à terminé, le main lui redonne du travail à faire,
    Tant qu'aucun thread n'a trouvé. et il incrémente sa variable <A_trouver_max>
    Pour donner du travail au suivant.
*/

int main(int argc, char const *argv[])
{
    if (argc < 2)
    {
        std::cerr << "Veuillez renseigner le nombre de threads à créer puis le MD5." << std::endl;
        return 1;
    }

    std::string s(argv[1]);
    long nb_thread;

    try
    {
        nb_thread = std::stoi(s);
    }
    catch (std::invalid_argument const & e)
    {
        std::cerr << e.what() << "()-> Le premier paramètre doit être le nombre de threads à créer." << std::endl;
        return 1;
    }
    catch (std::out_of_range const & e)
    {
        std::cerr << e.what() << "()-> Le nombre de thread est trop grand ( x < 65336 )." << std::endl;
        return 1;
    }

    if (nb_thread < 0)
    {
        std::cerr << "Le nombre de threads à créer doit être positif." << std::endl;
        return 1;
    }

    if (nb_thread % 4 != 0)
    {
        std::cerr << "Le nombre de threads doit être un multiple de 4." << std::endl;
        //return 1;
    }


    // - - - - - - - - - - - - - - - - - - - - - - - -
    // FIN DES VÉRIFICATIONS -> DÉBUT DU PROGRAMME :
    // - - - - - - - - - - - - - - - - - - - - - - - -

    std::string tmp_md5(argv[2]);

    std::cout << "Création de " << nb_thread << " threads. Recherche du md5 : "<< tmp_md5 << "." << std::endl;
    ThreadManager * manager = new ThreadManager(nb_thread, tmp_md5);

    uint16_t ready_thread_id = 0;
    uint16_t max_thread_started = 0;

    while (!manager->resultFound())
    {
        // Si un thread attend :
        if (manager->getFirstWaitingThread(ready_thread_id))
        {
            // Alors on l'utilise :
            //std::cout << "Starting Thread n°" << ready_thread_id << " ." << std::endl;
            manager->startThread(ready_thread_id);
            ready_thread_id > max_thread_started ? max_thread_started++: max_thread_started;
        }
    }

    std::cout << "the result is : " << manager->getResult() << std::endl;
    std::cout << "Au max, " << max_thread_started + 1 << " threads on travaillés en même temps." << std::endl;

    delete manager;

    return 0;
}
