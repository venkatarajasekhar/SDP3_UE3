///////////////////////////////////////////////////////////////////////////
// Workfile : main.cpp
// Author : Reinhard Penn, Bernhard Selymes
// Date : 12.11.2012
// Description : Testdriver for the whole program
///////////////////////////////////////////////////////////////////////////

#include <vld.h>
#include <iostream>
#include <fstream>
#include "EpcosAdapter.h"
#include "NortelNetworksAdapter.h"

void Testcase(std::string const& testCase, std::string const& filename)
{
	IEpcos* epcosAdapter					= new EpcosAdapter;
	INortelNetworks* nortelNetworksAdapter	= new NortelNetworksAdapter;

	std::string const filenameRSA(filename+extensionRSA);
	std::string const filenameCaesar(filename+extensionCaesar);
	TEncoding encoding;

	std::cout << testCase << std::endl;

	std::cout << "Encrypt with Epcos, RSA: " << filename << " ... ";
	epcosAdapter->EncryptRSA(filename);
	std::cout << "Finished" << std::endl;
	
	std::cout << "Decrypt with Epcos, RSA: " << filenameRSA << " ... ";
	epcosAdapter->DecryptRSA(filenameRSA);
	std::cout << "Finished" << std::endl;
	
	encoding = eRSA;
	std::cout << "Encipher with NortelNetworks, RSA: " << filename << " ... ";
	nortelNetworksAdapter->Encipher(encoding,filename);
	std::cout << "Finished" << std::endl;
	
	std::cout << "Decipher with NortelNetworks, RSA: " << filenameRSA << " ... ";
	nortelNetworksAdapter->Decipher(encoding,filenameRSA);
	std::cout << "Finished" << std::endl;

	encoding = eCaesar;
	std::cout << "Encipher with NortelNetworks, Caesar: " << filename << " ... ";
	nortelNetworksAdapter->Encipher(encoding,filename);
	std::cout << "Finished" << std::endl;

	std::cout << "Decipher with NortelNetworks, Caesar: " << filenameCaesar << " ... ";
	nortelNetworksAdapter->Decipher(encoding,filenameCaesar);
	std::cout << "Finished" << std::endl;
	
	delete epcosAdapter;
	delete nortelNetworksAdapter;
}

int main()
{
	Testcase("Testcase0: File doesnt exist","testcase0.txt");
	Testcase("Testcase1: File is empty","testcase1.txt");
	Testcase("Testcase2: Ascii symbols","testcase2.txt");
	Testcase("Testcase3: Normal text","testcase3.txt");
	
	return 0;
}
