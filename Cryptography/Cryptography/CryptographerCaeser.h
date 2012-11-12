///////////////////////////////////////////////////////////////////////////
// Workfile : CryptographerCaesar.h
// Author : Reinhard Penn, Bernhard Selymes
// Date : 12.11.2012
// Description : Header of CryptographerCaesar.cpp
///////////////////////////////////////////////////////////////////////////

#ifndef CRYPTOGRAPHERCAESAR_H
#define CRYPTOGRAPHERCAESAR_H

#include "Cryptographer.h"

int const Characters = 256;
int const key = 7;

class CryptographerCaeser :
	public Cryptographer
{
public:
	void Decrypt();
	void Encrypt();
private:
	void EncryptCaesar(char& ch);
	void DecryptCaesar(char& ch);
};

#endif