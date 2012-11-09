#ifndef CRYPTOGRAPHER_H
#define CRYPTOGRAPHER_H

#include <fstream>
#include "Object.h"

class Cryptographer :
	public Object
{
public:
	virtual ~Cryptographer();
	virtual void Decrypt() = 0;
	virtual void Encrypt() = 0;
	bool ReadFile(std::string const& filename);
	bool WriteFile(std::string const& filename);
private:
	std::fstream mFileStream;
};

#endif