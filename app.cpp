#include "app.h"

void App::setReader(IReader *pReader) { m_pReader = pReader; }
void App::setTypeDetector(ITypeDetector *pTypeDetector) { m_pTypeDetector = pTypeDetector; }
void App::addDecoder(IDecoder *pDecoder) { m_decoders.push_back(pDecoder); }
void App::setMultiplier(IMultiplier *pMultiplier) { m_pMultiplier = pMultiplier; }
void App::addEncoder(IEncoder *pEncoder) { m_encoders.push_back(pEncoder); }
void App::setWriter(IWriter *pWriter) { m_pWriter = pWriter; }

App::~App()
{
	delete m_pReader;
	delete m_pTypeDetector;
	for( auto d : m_decoders ) delete d;
	delete m_pMultiplier;
	for( auto e : m_encoders ) delete e;
	delete m_pWriter;
}

void App::run()
{
		m_pReader->read();
}
