#ifndef EPCOSADAPTER_H
#define EPCOSADAPTER_H

class EpcosAdapter
{
	virtual void DecryptRSA(string const& filename);
	virtual void EncryptRSA(string const& filename);
}

#endif