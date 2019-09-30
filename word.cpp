#include "word.hpp"

Word::Word(std::string s) : _word(s)
{

}

Word::Word(char * c) : _word(c)
{

}

Word & Word::operator++(int amount)
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
            if (_word.rbegin()[++i] != _bornes[5])
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
