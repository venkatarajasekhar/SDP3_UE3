#ifndef EPCOSADAPTER_H
#define EPCOSADAPTER_H

#include <string>
#include "Object.h"
#include "IEpcos.h"
#include "Cryptographer.h"

std::string const extensionRSA = ".RSA";

class EpcosAdapter :
	public Object,
	public IEpcos
{
public:
	~EpcosAdapter();
	void DecryptRSA(std::string const& filename);
	void EncryptRSA(std::string const& filename);
};

#endif