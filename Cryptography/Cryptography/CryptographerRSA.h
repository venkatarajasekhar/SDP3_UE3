///////////////////////////////////////////////////////////////////////////
// Workfile : CryptographerRSA.h
// Author : Reinhard Penn, Bernhard Selymes
// Date : 12.11.2012
// Description : Header of CryptographerRSA.cpp
///////////////////////////////////////////////////////////////////////////

#ifndef CRYPTOGRAPHERRSA_H
#define CRYPTOGRAPHERRSA_H

#include "Cryptographer.h"



class CryptographerRSA :
	public Cryptographer
{
public:
	void Decrypt();
	void Encrypt();
private:
        int const e = 7;		//public key
        int const d = 23;	//private key
        int const n = 255;	
	void EncryptRSA(char& ch);
	void DecryptRSA(char& ch);
	int PowerModulo(int e, int d);
};

#endif
