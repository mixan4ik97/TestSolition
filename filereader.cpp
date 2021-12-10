#include "filereader.h"
#include <iostream>
#include <fstream>


FileReader::FileReader()
{
}


FileReader::~FileReader()
{
}

void		FileReader::setTypeDetector(ITypeDetector *pTypeDetector) { m_pTypeDetector = pTypeDetector; }
void		FileReader::set_file_name(const std::string a_filename) { fileName = a_filename; }
std::string	FileReader::get_file_name() { return fileName; }

void FileReader::read()
{
	if (fileName.empty()) {
		std::cout << "Warning: file name not specified.";
		return;
	}
	std::ifstream fileReader(fileName);
	if (!fileReader.is_open()){
		std::cout << "Warning: could not open file: "<< fileName;
		return;
	}
	std::string res;
	fileReader >> res;
	m_pTypeDetector->onMessage(res);
}
