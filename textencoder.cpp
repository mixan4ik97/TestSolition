#include "textencoder.h"
using namespace std;

void TextEncoder::setWriter(IWriter *pWriter) { m_pWriter = pWriter; }

void TextEncoder::onMessage(const string &message)
{
	string res = "*" + message;
	m_pWriter->onMessage(res);
}
