#include "../headers/word.hpp"



Word::Word() : _word("0")
{

}

Word::Word(std::string s) : _word(s)
{

}

Word::Word(char * c) : _word(c)
{

}

Word::Word(Word & w) : _word(w._word)
{

}

std::string decimal2string(__uint128_t value )
{
    __uint128_t tmp = value;
    char buffer[128];
    char* d = std::end(buffer);
    do
    {
        --d;
        *d = ("0123456789"[ tmp % 10 ]);
        tmp /= 10;
    } while ( tmp != 0 );

    int len = std::end( buffer ) - d;

    return std::string(d, len);
}

char int2char(int number)
{
    if (number < -1 || number > 62)
        throw std::out_of_range("int2char() -> The given argument is too big or negativ. Tips -> [0;62].");

    if (number == -1)
    {
        return char('z');
    }
    else if (number >= 0 && number <= 9)
    {
        return char(number+48);
    }
    else if (number >= 10 && number <= 35)
    {
        return char(number+55);
    }
    else
    {
        return char(number+61);
    }
}

char * int2charE(int number)
{
    if (number < -1 || number > 99)
        throw std::out_of_range("int2char() -> The given argument is too big or negativ. Tips -> [0;62].");

    if (number < 10)
    {
        return new char(number+48);
    }
    else
    {
        return new char[2] {char((int)number/10+48), char((int)number%10+48) };
    }
}

Word::Word(__uint128_t i) : _word("0")
{
    if ( i > 62)
    {
        uint64_t tmp = 0;

        __uint128_t divided = i;
        size_t length = 0;

        uint16_t * rest = new uint16_t[40];

        for (; divided > 62; ++length)
        {
            tmp = divided / 62;
            rest[length] = divided % 62;
            divided = tmp;
        }


        char * new_word = new char[length];

        // Première lettre :
        new_word[0] = int2char(divided-1);
        // Lettre jusqu'a n-1 :
        for (size_t i = 1; i < length; i++)
        {
            new_word[i] = int2char(rest[length - i]-1);
        }
        // Lettre n :
        new_word[length] = int2char(rest[0]);

        _word = std::string(new_word, length+1);

        delete [] new_word;
        delete [] rest;
    }
    else
    {

        char * tmp = int2charE(i);
        _word = std::string(tmp, i > 9?2:1);
        delete [] tmp;
    }

}

Word & Word::operator++()
{
    /*      SI :
    -/ '0' <= c < '9'       |       48 <= c < 57
    -/ 'A' <= c < 'Z'       |       65 <= c < 90
    -/ 'a' <= c < 'z'       |       97 <= c < 122
    */
    if ((*_word.rbegin() >= _bornes[0] && *_word.rbegin() < _bornes[1])
        || (*_word.rbegin() >= _bornes[2] && *_word.rbegin() < _bornes[3])
        || (*_word.rbegin() >= _bornes[4] && *_word.rbegin() < _bornes[5]))
    {
        // Tout va bien :
        ++*(_word.rbegin());
    }
    else if (*_word.rbegin() == _bornes[1])
    {
        *(_word.rbegin()) +=  8;
    }
    else if (*_word.rbegin() == _bornes[3])
    {
        *(_word.rbegin()) +=  7;
    }
    else if (*_word.rbegin() == _bornes[5])
    {
        for (size_t i = 0; i < _word.length();)
        {
            _word.rbegin()[i] = _bornes[0];
            if (i == _word.length()-1)
            {
                _word.insert(0, 1, '0');
                break;
            }
            else if (_word.rbegin()[++i] != _bornes[5])
            {
                if ((_word.rbegin()[i] >= _bornes[0] && _word.rbegin()[i] < _bornes[1])
                    || (_word.rbegin()[i] >= _bornes[2] && _word.rbegin()[i] < _bornes[3])
                    || (_word.rbegin()[i] >= _bornes[4] && _word.rbegin()[i] < _bornes[5]))
                {
                    // Tout va bien :
                    _word.rbegin()[i]++;
                }
                else if (_word.rbegin()[i] == _bornes[1])
                {
                    _word.rbegin()[i] +=  8;
                }
                else if (_word.rbegin()[i] == _bornes[3])
                {
                    _word.rbegin()[i] +=  7;
                }
                break;
            }
        }
    }

    return *this;
}

Word Word::operator++(int amount)
{
    Word tmp(*this);
    operator++();
    return tmp;
}
