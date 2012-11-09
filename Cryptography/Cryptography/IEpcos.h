#ifndef IEPCOS_H
#define IEPCOS_H

#include <string>

class IEpcos
{
	virtual void DecryptRSA(std::string const& filename) = 0;
	virtual void EncryptRSA(std::string const& filename) = 0;
};

#endif