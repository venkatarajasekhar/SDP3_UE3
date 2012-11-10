#include <vld.h>
#include <iostream>
#include <fstream>
#include "EpcosAdapter.h"
#include "NortelNetworksAdapter.h"

using namespace std;

int main()
{
	//create compare file
	string const cmp = "!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^`abcdefghijklmnopqrstuvwxyz_~{|}";

	fstream f1;
	f1.open("test1.txt",fstream::out | fstream::trunc);	//delete whole content
	f1 << cmp;
	f1.close();

	fstream f;
	f.open("test.txt",fstream::out | fstream::trunc);
	f << cmp;
	f.close();

	IEpcos* ie1 = new EpcosAdapter;

	ie1->EncryptRSA("test.txt");
	ie1->DecryptRSA("test.txt.RSA");

	//string 1
	string str1;
	ifstream file("test.txt");
	if (file)
	{
		str1 = string(istreambuf_iterator<char>(file),std::istreambuf_iterator<char>());
	}
	file.close();

	//string 2
	string str2;
	ifstream file1("test1.txt");
	if (file1)
	{
		str2 = string(istreambuf_iterator<char>(file1),std::istreambuf_iterator<char>());
	}
	file1.close();

	if(str1 == str2)
	{
		cout << "Compare Test successful!" << endl;
	}

	delete ie1;


	INortelNetworks* NorNet = new NortelNetworksAdapter;
	string Filename("NortelTest.txt");

	fstream stream;
	stream.open(Filename,fstream::out | fstream::trunc);	//delete whole content
	stream << cmp << endl << "Hallo" << endl;
	stream.close();

	NorNet->Encipher(eCaesar,Filename);
	NorNet->Decipher(eCaesar,Filename+extensionCaesar);

	delete NorNet;

	return 0;
}
