#include "consolereader.h"
#include <iostream>

using namespace std;

void ConsoleReader::setTypeDetector(ITypeDetector *pTypeDetector) { m_pTypeDetector = pTypeDetector; }

void ConsoleReader::read()
{
	string res;
	cin >> res;
	m_pTypeDetector->onMessage(res);
}
