#pragma once
#include "itypedetector.h"

enum TypeReader {
	CONSOLE_READER,
	FILE_READER
};

struct IReader
{
	virtual ~IReader() = default;
	virtual void read() = 0;
public:
	virtual void setTypeDetector(ITypeDetector *pTypeDetector) = 0;
};