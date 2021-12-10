#pragma once
#include "consolewriter.h"
#include <iostream>
using namespace std;

void ConsoleWriter::onMessage(const string &message)
{
	cout << message << endl;
}
