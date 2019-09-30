#ifndef WORD_HPP
#define WORD_HPP

#include <cstdint>
#include <iostream>
#include <string>

static uint8_t _bornes[] = {48, 57, 65, 90, 97, 122};

class Word
{
private:
    std::string _word;


public:
    Word() = delete;
    Word(std::string s);
    Word(char * c);
    Word & operator++(int);

    friend std::ostream & operator<<(std::ostream & os, const Word & obj)
    {
        return os << obj._word;
    }
};



#endif /* end of include guard: WORD_HPP */
