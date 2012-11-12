///////////////////////////////////////////////////////////////////////////
// Workfile : IEpcos.h
// Author : Reinhard Penn, Bernhard Selymes
// Date : 12.11.2012
// Description : Interface for Epcos
///////////////////////////////////////////////////////////////////////////

#ifndef IEPCOS_H
#define IEPCOS_H

#include <string>

class EpcosAdapter;

class IEpcos
{
public:
	virtual ~IEpcos() {};
	virtual void DecryptRSA(std::string const& filename) = 0;
	virtual void EncryptRSA(std::string const& filename) = 0;
};

#endif