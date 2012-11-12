///////////////////////////////////////////////////////////////////////////
// Workfile : EpcosAdapter.h
// Author : Reinhard Penn, Bernhard Selymes
// Date : 12.11.2012
// Description : Header of EpcosAdapter.cpp
///////////////////////////////////////////////////////////////////////////

#ifndef EPCOSADAPTER_H
#define EPCOSADAPTER_H

#include <string>
#include "Object.h"
#include "IEpcos.h"
#include "Cryptographer.h"

class EpcosAdapter :
	public Object,
	public IEpcos
{
public:
	~EpcosAdapter();
	void DecryptRSA(std::string const& filename);
	void EncryptRSA(std::string const& filename);
};

#endif