#ifndef INORTELNETWORKS_H
#define INORTELNETWORKS_H

class INortelNetworks
{
	virtual void Decipher(TEncoding encoding, string const& filename) = 0;
	virtual void Encipher(TEncoding encoding, string const& filename) = 0;
}

#endif