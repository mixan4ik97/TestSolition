#pragma once
#include <vector>
#include "ireader.h"
#include "itypedetector.h"
#include "idecoder.h"
#include "imultiplier.h"
#include "iencoder.h"
#include "iwriter.h"

class App
{
public:
	~App();
	void setReader(IReader *pReader);
	void setTypeDetector(ITypeDetector *pTypeDetector);
	void addDecoder(IDecoder *pDecoder);
	void setMultiplier(IMultiplier *pMultiplier);
	void addEncoder(IEncoder *pEncoder);
	void setWriter(IWriter *pWriter);

	void run();

protected:
	IReader *m_pReader = nullptr;
	ITypeDetector *m_pTypeDetector = nullptr;
	std::vector<IDecoder*> m_decoders;
	IMultiplier *m_pMultiplier = nullptr;
	std::vector<IEncoder*> m_encoders;
	IWriter *m_pWriter = nullptr;
private:

};