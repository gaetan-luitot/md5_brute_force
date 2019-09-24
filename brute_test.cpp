#include <cstdint>
#include <string>

char dico[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

uint8_t dico_size = 26;

int main(int argc, char const *argv[])
{
    std::string mdp = "salut";

    bool found = false;

    while (!found)
    {
        for (size_t i = 0; i < dico_size; i++)
        {
            if (mdp[i] == 1) {
                /* code */
            }
        }
    }

    return 0;
}
