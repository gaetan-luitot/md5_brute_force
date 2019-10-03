#include <iostream>
#include "../headers/word.hpp"

int main(int argc, char const *argv[])
{
    Word * mot = new Word();

    for (size_t i = 0; i < 100; ++i)
    {
        std::cout << (*mot)++ << std::endl;
    }

    delete mot;
    return 0;
}
