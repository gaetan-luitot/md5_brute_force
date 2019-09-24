#ifndef LETTER_HPP
#define LETTER_HPP

#include <cstdint>

static char values[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

class Letter
{
private:
    char _value;

public:
    Letter & operator++();
    Letter & operator--();

};

Letter & operator+=(const Letter & rhs, int);

#endif /* end of include guard: LETTER_HPP */
