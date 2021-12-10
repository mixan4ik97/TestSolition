#pragma once
#include "idecoder.h"

class TextDecoder : public IDecoder
{
public:
	void setMultiplier(IMultiplier *pMultiplier);
	void onMessage(const std::string &encodedMessage, DataType dataType) override;
	
protected:
	IMultiplier *m_pMultiplier = nullptr;
};