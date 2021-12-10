#pragma once
#include "itypedetector.h"
#include "imultiplier.h"
#include "textdecoder.h"

class TypeDetector : public ITypeDetector
{
public:
	void setMultiplier(IMultiplier *pMultiplier);
	void setTextDecoder(IDecoder *pTextDecoder);
	std::string DecodeFacade(const std::string &msg) ;

	virtual void onMessage(const std::string &msg) override;

protected:
	IMultiplier *m_pMupliplier = nullptr;
	IDecoder *m_pTextDecoder = nullptr;
};