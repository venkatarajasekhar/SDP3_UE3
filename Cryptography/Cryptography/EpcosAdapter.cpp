#include <string>
#include "EpcosAdapter.h"
#include "CryptographerRSA.h"

using namespace std;

EpcosAdapter::~EpcosAdapter()
{
}

void EpcosAdapter::DecryptRSA(string const& filename)
{
	Cryptographer* cryptographer = new CryptographerRSA;
	cryptographer->ReadFile(filename);					//e.g. test.txt.RSA
	cryptographer->Decrypt();
	cryptographer->WriteFile(filename.substr(0,filename.size()-(extensionRSA.size())));	//e.g. test.txt
	delete cryptographer;
}

void EpcosAdapter::EncryptRSA(string const& filename)
{
	Cryptographer* cryptographer = new CryptographerRSA;
	cryptographer->ReadFile(filename);					//e.g. test.txt
	cryptographer->Encrypt();
	cryptographer->WriteFile(filename+extensionRSA);	//e.g. test.txt.RSA
	delete cryptographer;
}