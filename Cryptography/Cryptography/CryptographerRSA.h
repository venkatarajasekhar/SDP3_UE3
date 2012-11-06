#ifndef CRYPTOGRAPHERRSA_H
#define CRYPTOGRAPHERRSA_H

class CryptographerRSA :
	public Cryptographer
{
public:
	virtual void Decrypt();
	virtual void Encrypt();
}

#endif