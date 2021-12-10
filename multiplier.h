#pragma once
#include <string>
#include "imultiplier.h"
#include "iencoder.h"
#include "iwriter.h"

class Multiplier : public IMultiplier
{
public:
	void setWriter(IWriter *pWriter);
	void setTextEncoder(IEncoder *pEncoder);
	void onDecodedMessage(const std::string &message, DataType dataType) override;

protected:
	void passFurther(const std::string &msg, DataType dataType);

	IWriter *m_pWriter = nullptr;
	IEncoder *m_pEncoder = nullptr;
};
