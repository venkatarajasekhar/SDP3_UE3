///////////////////////////////////////////////////////////////////////////
// Workfile : INortelNetworks.h
// Author : Reinhard Penn, Bernhard Selymes
// Date : 12.11.2012
// Description : Interface for NortelNetworks
///////////////////////////////////////////////////////////////////////////

#ifndef INORTELNETWORKS_H
#define INORTELNETWORKS_H

#include <string>
#include "TEncoding.h"

class INortelNetworks
{
public:
	virtual ~INortelNetworks() {};
	virtual void Decipher(TEncoding encoding, std::string const& filename) = 0;
	virtual void Encipher(TEncoding encoding, std::string const& filename) = 0;
};

#endif