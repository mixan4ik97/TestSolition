#pragma once
#include "iencoder.h"
#include "iwriter.h"

class TextEncoder : public IEncoder
{
public:
	void setWriter(IWriter *pWriter);
	void onMessage(const std::string &message) override;

protected:
	IWriter *m_pWriter = nullptr;
};