#include <iostream>
#include "../headers/word.hpp"

int main(int argc, char const *argv[])
{
    Word * mot = new Word();
		std::string whatIWantToFind(argv[1]);
		std::string currentWord;

		do {
			currentWord = cpp_md5sum((*mot).getString());
			if (currentWord != whatIWantToFind) {
				(*mot)++;
			}
		} while(whatIWantToFind != currentWord);

    std::cout << (*mot) << std::endl;

    delete mot;
    return 0;
}
