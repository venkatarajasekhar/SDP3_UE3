#include <vld.h>
#include <iostream>
#include <fstream>
#include "EpcosAdapter.h"

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

	return 0;
}
