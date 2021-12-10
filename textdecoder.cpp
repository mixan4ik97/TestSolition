#include "textdecoder.h"
using namespace std;

void TextDecoder::setMultiplier(IMultiplier *pMultiplier) { m_pMultiplier = pMultiplier; }

void TextDecoder::onMessage(const string &encodedMessage, DataType dataType)
{
	string decoded;
	for( char c : encodedMessage )
		decoded += to_string( static_cast<int>(c) );
	m_pMultiplier->onDecodedMessage(decoded, dataType);
}
