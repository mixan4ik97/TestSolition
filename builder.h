#pragma once
#include "app.h"
#include <memory>

struct Builder
{
	static std::unique_ptr<App> build(const TypeReader &a_type_reader, const std::string a_filename);
};