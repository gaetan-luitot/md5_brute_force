#include <iostream>
#include "word.hpp"
#include <string>

// THREADS :
#include <pthread.h>

struct data
{
    size_t number;
};

void * func(void * arg)
{
    data * infos = (data *)arg;

    std::cout << "I'm thread n° "<< infos->number << "."<< std::endl;

    return arg;
}

int main(int argc, char const *argv[])
{
    if (argc > 1)
    {
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
            return 1;
        }

        std::cout << "Création de " << nb_thread << " threads." << std::endl;

        pthread_t * threads = new pthread_t[nb_thread];
        data * set_of_datas = new data[nb_thread];

        for (size_t i = 0; i < nb_thread; i++)
        {
            set_of_datas[i].number = i;
            pthread_create(&threads[i], NULL, func, (void *)&set_of_datas[i]);
        }

        /*
        Word * mot = new Word();

        for (size_t i = 0; i < 100; ++i)
        {
            std::cout << (*mot)++ << std::endl;
        }

        delete mot;
        */
    }
    else
        std::cout << "Veuillez renseigner le nombre de threads à créer." << std::endl;

    return 0;
}
