#ifndef CRYPTOGRAPHERCAESAR_H
#define CRYPTOGRAPHERCAESAR_H

#include "Cryptographer.h"

class CryptographerCaeser :
	public Cryptographer
{
public:
	void Decrypt();
	void Encrypt();
};

#endif