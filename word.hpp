#ifndef WORD_HPP
#define WORD_HPP

#include <cstdint>
#include <string>


class Word
{
private:
    std::string _word;
    Word & operator++();

public:
    Word();
};

#endif /* end of include guard: WORD_HPP */
