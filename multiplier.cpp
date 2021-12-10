#include "multiplier.h"

using namespace std;

void Multiplier::setWriter(IWriter *pWriter) { m_pWriter = pWriter; }
void Multiplier::setTextEncoder(IEncoder *pEncoder) { m_pEncoder = pEncoder; }

void Multiplier::onDecodedMessage(const std::string &message, DataType dataType)
{
	string res;
	for( char c : message )
	{
		int n = c - '0';
		n *= 2;
		res += to_string(n);
	}

	passFurther(res, dataType);
}

void Multiplier::passFurther(const std::string &msg, DataType dataType)
{
	if (dataType == DataType::TEXT)
		m_pWriter->onMessage(msg);
	else 
		m_pWriter->onMessage(msg);

}