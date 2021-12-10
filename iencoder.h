#pragma once
#include <string>

struct IEncoder
{
	virtual ~IEncoder() = default;
	virtual void onMessage(const std::string &message) = 0;
};