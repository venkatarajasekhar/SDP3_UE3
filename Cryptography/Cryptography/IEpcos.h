#ifndef IEPCOS_H
#define IEPCOS_H

class IEpcos
{
	virtual void DecryptRSA(string const& filename) = 0;
	virtual void EncryptRSA(string const& filename) = 0;
}

#endif