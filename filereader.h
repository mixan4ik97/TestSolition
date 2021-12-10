#pragma once
#include "ireader.h"
#include "itypedetector.h"


class FileReader : public IReader
{
public:
	FileReader();
	FileReader(const std::string &fn) { set_file_name(fn);}
	~FileReader();
	void setTypeDetector(ITypeDetector *pTypeDetector) override;
	void read() override;
	void		set_file_name(const std::string a_filename);
	std::string	get_file_name();
protected:
	ITypeDetector *m_pTypeDetector = nullptr;
	std::string fileName;
};

