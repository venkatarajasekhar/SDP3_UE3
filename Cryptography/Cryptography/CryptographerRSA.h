#ifndef CRYPTOGRAPHERRSA_H
#define CRYPTOGRAPHERRSA_H

#include "Cryptographer.h"

class CryptographerRSA :
	public Cryptographer
{
public:
	void Decrypt();
	void Encrypt();
};

#endif