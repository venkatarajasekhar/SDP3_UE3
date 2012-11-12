///////////////////////////////////////////////////////////////////////////
// Workfile : NortelNetworksAdapter.h
// Author : Reinhard Penn, Bernhard Selymes
// Date : 12.11.2012
// Description : Header of NortelNetworksAdapter.cpp
///////////////////////////////////////////////////////////////////////////

#ifndef NORTELNETWORKSADAPTER_H
#define NORTELNETWORKSADAPTER_H

#include <string>
#include "Object.h"
#include "INortelNetworks.h"
#include "Cryptographer.h"

class NortelNetworksAdapter :
	public Object,
	public INortelNetworks
{
public:
	void Decipher(TEncoding encoding, std::string const& filename);
	void Encipher(TEncoding encoding, std::string const& filename);
};

#endif