#ifndef CRYPTOGRAPHER_H
#define CRYPTOGRAPHER_H

class Cryptographer :
	public Object
{
public:
	virtual void Decrypt() = 0;
	virtual void Encrypt() = 0;
	bool ReadFile(string const& filename);
	bool WriterFile(string const& filename);
private:
	std::fstream mFileStream;
}

#endif