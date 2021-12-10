#pragma once
#include <string>
#include "datatype.h"

struct IMultiplier
{
	virtual ~IMultiplier() = default;

	virtual void onDecodedMessage(const std::string &message, DataType dataType) = 0;
};