#include <fstream>
#include <sstream>
#include <string>
#include "Cryptographer.h"

using namespace std;

Cryptographer::~Cryptographer()
{}

void Cryptographer::ReadFile(string const& filename)
{
	FileToString(filename);
}

void Cryptographer::WriteFile(string const& filename)
{
	fstream file(filename, fstream::out);	//create new file, if it doesnt exsist
	if(file)
	{
		file << mData;
	}
	file.close();
}

void Cryptographer::FileToString(string const& filename)
{
    ifstream file(filename);
    if (file)
    {
		mData = string(istreambuf_iterator<char>(file),std::istreambuf_iterator<char>());
    }
	file.close();
}

