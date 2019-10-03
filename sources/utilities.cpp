#include "utilities.hpp"

std::string cpp_md5sum(std::string word) {
	//On créer un tableau de char qui fait la longueur d'une empreinte md5.
	//std::unique_ptr<unsigned char> md5Print(new unsigned char[MD5_DIGEST_LENGTH]);
	unsigned char md5Print[MD5_DIGEST_LENGTH];

	//On calcul le md5.
	MD5((unsigned char*)(word.c_str()), word.size(), md5Print);

	//On converti en string
std::ostringstream sout;
sout<<std::hex<<std::setfill('0');
for(long long c : md5Print)
{
    sout<<std::setw(2)<<(long long)c;
}

	//On renvoie un string généré à l'aide de notre c_str.
	return std::string((char*)(md5Print));
}
