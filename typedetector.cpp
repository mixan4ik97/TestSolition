#include "typedetector.h"
#include <cctype>
#include "Base64Decoder.h"

using namespace std;

void TypeDetector::setMultiplier(IMultiplier *pMultiplier) { m_pMupliplier = pMultiplier; }
void TypeDetector::setTextDecoder(IDecoder *pTextDecoder) { m_pTextDecoder = pTextDecoder; }


string TypeDetector::DecodeFacade(const std::string &msg) {
	const char first_char = msg[0];
	string ret;
	switch (first_char) {
		case '=':  ret = Base64Decoder::base64_decode(msg); break;
		default:
			ret = msg;
	}
	return ret;
}

void TypeDetector::onMessage(const string &msg)
{
	string d_msg = DecodeFacade(msg);
	DataType dataType = DataType::TEXT;
	for( char c : d_msg)
		if( !isdigit(c) )
		{
			dataType = DataType::BINARY;
			break;
		}
	
	if( dataType == DataType::BINARY )
		m_pTextDecoder->onMessage(d_msg, dataType);
	else
		m_pMupliplier->onDecodedMessage(d_msg, dataType);
}
