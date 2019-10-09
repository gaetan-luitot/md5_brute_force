#include "../headers/word.hpp"
#include <iostream>

int main(int argc, char const *argv[])
{

    if (argc > 1)
    {
        Word mot(argv[1]);
        mot++;
        std::cout << "---> " << mot << std::endl;
    }


    /*
    for (size_t i = 0; i < 50; i++)
    {
        std::cout << mot << std::endl;
    }
    */
    return 0;
}
