#include <string>
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

	delete cryptographer;
}