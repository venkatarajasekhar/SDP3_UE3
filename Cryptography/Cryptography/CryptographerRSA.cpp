///////////////////////////////////////////////////////////////////////////
// Workfile : CryptographerRSA.cpp
// Author : Reinhard Penn, Bernhard Selymes
// Date : 12.11.2012
// Description : Implementation of class CryptographerRSA
///////////////////////////////////////////////////////////////////////////

#include "CryptographerRSA.h"
 using namespace std::string;



void CryptographerRSA::Decrypt()
{
	iterator itor;
	for(itor = mData.begin();itor != mData.end();++itor)
	{
		DecryptRSA(itor);
	}
	return;
}

void CryptographerRSA::Encrypt()
{
	iterator itor;
	for(itor = mData.begin();itor != mData.end();++itor)
	{
		EncryptRSA(itor);
	}
	return;
}

void CryptographerRSA::EncryptRSA(char& ch)
{
	unsigned char tmp = ch;
	unsigned char Retval;
	Retval = PowerModulo(int(tmp),e);
	ch = Retval;
	return;
}

void CryptographerRSA::DecryptRSA(char& ch)
{
	unsigned char tmp = ch;
	unsigned char Retval;
	Retval = PowerModulo(int(tmp),d);
	ch = Retval;
	return;
}

//calculate x^(e|d) mod n
int CryptographerRSA::PowerModulo(int x, int Powmodvar)
{ 
	int result = 1;
	for (int i = 0; i < Powmodvar; ++i)
	{
		result = (result * x) % n;
	}
	return result; 
}

