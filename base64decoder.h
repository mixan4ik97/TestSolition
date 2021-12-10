#pragma once
#include <string>

class Base64Decoder {
public:
	static std::string base64_decode(const std::string &encoded_string);
};