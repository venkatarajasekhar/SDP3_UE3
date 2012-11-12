///////////////////////////////////////////////////////////////////////////
// Workfile : EpcosAdapter.cpp
// Author : Reinhard Penn, Bernhard Selymes
// Date : 12.11.2012
// Description : Implementation of the Adapter for Epcos
///////////////////////////////////////////////////////////////////////////

#include <string>
#include <iostream>
#include "EpcosAdapter.h"
#include "CryptographerRSA.h"

EpcosAdapter::~EpcosAdapter()
{
}

void EpcosAdapter::DecryptRSA(std::string const& filename)
{
	Cryptographer* cryptographer = new CryptographerRSA;
	try {
		cryptographer->ReadFile(filename);					//e.g. test.txt.RSA
		cryptographer->Decrypt();
		cryptographer->WriteFile(filename.substr(0,filename.size()-(extensionRSA.size())));	//e.g. test.txt
	}
	catch(std::string const& ex)
	{
		std::cerr << "EpcosAdapter.cpp::DecryptRSA: " << ex << std::endl;
	}
	catch(...)
	{
		std::cerr << "EpcosAdapter::DecryptRSA: Unknown Exception occured" << std::endl;
	}
	delete cryptographer;
}

void EpcosAdapter::EncryptRSA(std::string const& filename)
{
	Cryptographer* cryptographer = new CryptographerRSA;
	try {
		cryptographer->ReadFile(filename);					//e.g. test.txt
		cryptographer->Encrypt();
		cryptographer->WriteFile(filename+extensionRSA);	//e.g. test.txt.RSA
	}
	catch(std::string const& ex)
	{
		std::cerr << "EpcosAdapter::EncryptRSA: " << ex << std::endl;
	}
	catch(...)
	{
		std::cerr << "EpcosAdapter::EncryptRSA: Unknown Exception occured" << std::endl;
	}
	delete cryptographer;
}