#pragma once
#include <string>


struct IWriter
{
	virtual ~IWriter() = default;
	virtual void onMessage(const std::string &message) = 0;
};