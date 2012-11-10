#include <fstream>
#include <sstream>
#include <string>
#include "Cryptographer.h"

Cryptographer::~Cryptographer()
{}

void Cryptographer::ReadFile(std::string const& filename)
{
	FileToString(filename);
}

void Cryptographer::WriteFile(std::string const& filename)
{
	std::fstream file(filename, std::fstream::out);	//create new file, if it doesnt exsist
	if(file)
	{
		file << mData;
	}
	file.close();
}

void Cryptographer::FileToString(std::string const& filename)
{
    std::ifstream file(filename);
    if (file)
    {
		mData = std::string(std::istreambuf_iterator<char>(file),std::istreambuf_iterator<char>());
    }
	file.close();
}

