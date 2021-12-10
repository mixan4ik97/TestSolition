#pragma once
#include "ireader.h"
#include "itypedetector.h"

class ConsoleReader : public IReader
{
public:
	void setTypeDetector(ITypeDetector *pTypeDetector) override; 
	void read() override;

protected:
	ITypeDetector *m_pTypeDetector = nullptr;
};
