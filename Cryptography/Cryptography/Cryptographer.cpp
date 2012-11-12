///////////////////////////////////////////////////////////////////////////
// Workfile : Cryptographer.cpp
// Author : Reinhard Penn, Bernhard Selymes
// Date : 12.11.2012
// Description : Implementation of class Cryptographer
///////////////////////////////////////////////////////////////////////////

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
	if(!file.is_open())
	{
		std::string ex("File couldn't be opened");
		throw(ex);
	}
	file << mData;
	file.close();
}

void Cryptographer::FileToString(std::string const& filename)
{
		std::ifstream file(filename);
		if (!file.is_open())
		{
			std::string ex("File couldn't be opened");
			throw(ex);
		}
		mData = std::string(std::istreambuf_iterator<char>(file),std::istreambuf_iterator<char>());
		file.close();
}

