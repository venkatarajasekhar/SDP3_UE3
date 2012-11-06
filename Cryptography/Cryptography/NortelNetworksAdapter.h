#ifndef NORTELNETWORKSADAPTER_H
#define NORTELNETWORKSADAPTER_H

class NortelNetworksAdapter :
	public Object
{
public:
	void Decipher(TEncoding encoding, string const& filename);
	void Encipher(TEncoding encoding, string const& filename);
}

#endif