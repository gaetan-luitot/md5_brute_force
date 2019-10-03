#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#include <string>
#include <memory>
#include <openssl/md5.h>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstring>

std::string cpp_md5sum(std::string word); //Charger d'encapsuler le calcul de l'empreinte md5.

#endif /* end of include guard: UTILITIES_HPP */
