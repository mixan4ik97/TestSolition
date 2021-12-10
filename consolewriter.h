#pragma once
#include "iwriter.h"

class ConsoleWriter : public IWriter
{
public:
	void onMessage(const std::string &message) override;
};