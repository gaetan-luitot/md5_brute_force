#include "word.hpp"

Word::Word() : _word("salit")
{

}

Word & Word::operator++(int amount)
{
    std::cout << *(++_word.rbegin()) << std::endl;
}
