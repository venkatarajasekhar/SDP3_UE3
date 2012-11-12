///////////////////////////////////////////////////////////////////////////
// Workfile : CryptographerCaesar.cpp
// Author : Reinhard Penn, Bernhard Selymes
// Date : 12.11.2012
// Description : Implementation of class CryptographerCaesar
///////////////////////////////////////////////////////////////////////////

#include "CryptographerCaeser.h"

void CryptographerCaeser::Decrypt()
{
	std::string::iterator itor;
	for(itor = mData.begin();itor != mData.end();++itor)
	{
		DecryptCaesar(*itor);
	}
}

void CryptographerCaeser::Encrypt()
{
	std::string::iterator itor;
	for(itor = mData.begin();itor != mData.end();++itor)
	{
		EncryptCaesar(*itor);
	}
}

void CryptographerCaeser::EncryptCaesar(char& ch)
{
	ch = (ch + key) % Characters;
}

void CryptographerCaeser::DecryptCaesar(char& ch)
{
	ch = (ch - key + Characters) % Characters;
}