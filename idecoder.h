#pragma once
#include <string>
#include "datatype.h"
#include "imultiplier.h"

struct IDecoder
{
	virtual ~IDecoder() = default;
	virtual void onMessage(const std::string &encodedMessage, DataType dataType) = 0;
};