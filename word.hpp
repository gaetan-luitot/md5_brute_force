#ifndef WORD_HPP
#define WORD_HPP

#include <cstdint>
#include <iostream>
#include <string>

#include "utilities.hpp"

static uint8_t _bornes[] = {48, 57, 65, 90, 97, 122};

class Word
{
private:
    std::string _word;


public:
	//Constructeur----------------------------------------------------------------
    Word();
    Word(std::string s);
    Word(char * c);
    Word(Word & w);

    Word & operator++();
    Word operator++(int); // pre-increment

	inline std::string getString() const { return _word; }

    friend std::ostream & operator<<(std::ostream & os, Word const & obj)
    {
        return os << obj.getString();
    }

		inline std::string calcMd5() { return cpp_md5sum(getString()); }
};

#endif /* end of include guard: WORD_HPP */
