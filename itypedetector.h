#pragma once
#include <string>
#include "datatype.h"

struct ITypeDetector
{
	virtual ~ITypeDetector() = default;

	virtual void onMessage(const std::string &msg) = 0;
	virtual std::string DecodeFacade(const std::string &msg) = 0; // По хорошему, необходимо добавлять ещё один отдельный класс "DecodeFacade". 
};