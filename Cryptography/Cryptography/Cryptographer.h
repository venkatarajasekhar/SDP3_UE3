///////////////////////////////////////////////////////////////////////////
// Workfile : Cryptographer.h
// Author : Reinhard Penn, Bernhard Selymes
// Date : 12.11.2012
// Description : Header of Cryptographer.cpp
///////////////////////////////////////////////////////////////////////////

#ifndef CRYPTOGRAPHER_H
#define CRYPTOGRAPHER_H

#include <string>
#include "Object.h"

std::string const extensionRSA = ".RSA";
std::string const extensionCaesar = ".Caesar";
std::string const extensionDecrypted = ".Decrypted";

class Cryptographer :
	public Object
{
public:
	virtual ~Cryptographer();
	virtual void Decrypt() = 0;
	virtual void Encrypt() = 0;
	void ReadFile(std::string const& filename);
	void WriteFile(std::string const& filename);
protected:
	std::string mData;
private:
	void FileToString(std::string const& filename);
};

#endif