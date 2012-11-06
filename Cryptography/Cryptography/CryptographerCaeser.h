#ifndef CRYPTOGRAPHERCAESAR_H
#define CRYPTOGRAPHERCAESAR_H

class CryptographerCaeser :
	public Cryptographer
{
public:
	virtual void Decrypt();
	virtual void Encrypt();
}

#endif