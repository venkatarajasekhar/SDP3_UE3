///////////////////////////////////////////////////////////////////////////
// Workfile : NortelNetworksAdapter.cpp
// Author : Reinhard Penn, Bernhard Selymes
// Date : 12.11.2012
// Description : Implementation of the Adapter for NortelNetworks
///////////////////////////////////////////////////////////////////////////

#include <string>
#include <iostream>
#include "NortelNetworksAdapter.h"
#include "CryptographerCaeser.h"
#include "CryptographerRSA.h"

using namespace std;

void NortelNetworksAdapter::Decipher(TEncoding encoding, string const& filename)
{
	Cryptographer* cryptographer;

	if (encoding == eCaesar)
	{
		cryptographer = new CryptographerCaeser;
	}
	else
	{
		cryptographer = new CryptographerRSA;
	}

	try {
		cryptographer->ReadFile(filename);
		cryptographer->Decrypt();
		if (encoding == eCaesar)
		{
			cryptographer->WriteFile(filename.substr(0,filename.size()-(extensionCaesar.size())));	//e.g. test.txt
		}
		else
		{
			cryptographer->WriteFile(filename.substr(0,filename.size()-(extensionRSA.size())));	//e.g. test.txt
		}
	}
	catch(std::string const& ex)
	{
		std::cerr << "NortelNetworksAdapter::Decipher: " << ex << std::endl;
	}
	catch(...)
	{
		std::cerr << "NortelNetworksAdapter::Decipher: Unknown Exception occured" << std::endl;
	}

	delete cryptographer;
}

void NortelNetworksAdapter::Encipher(TEncoding encoding, string const& filename)
{
	Cryptographer* cryptographer;

	if (encoding == eCaesar)
	{
		cryptographer = new CryptographerCaeser;
	}
	else
	{
		cryptographer = new CryptographerRSA;
	}

	try {
		cryptographer->ReadFile(filename);
		cryptographer->Encrypt();

		if (encoding == eCaesar)
		{ 
			cryptographer->WriteFile(filename+extensionCaesar);	//e.g. test.txt.Caesar
		}
		else
		{
			cryptographer->WriteFile(filename+extensionRSA);	//e.g. test.txt.RSA
		}
	}
	catch(std::string const& ex)
	{
		std::cerr << "NortelNetworksAdapter::Encipher: " << ex << std::endl;
	}
	catch(...)
	{
		std::cerr << "NortelNetworksAdapter::Encipher: Unknown Exception occured" << std::endl;
	}

	delete cryptographer;
}