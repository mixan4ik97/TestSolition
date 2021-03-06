#include "builder.h"
#include <memory>

std::string ParseCommandLineParameters(int argc, const char *argv[], TypeReader &type_reader) {
	if (argc > 1) {
		type_reader = TypeReader::FILE_READER;
		return 	std::string(argv[1]);
	}
	type_reader = TypeReader::CONSOLE_READER;
	return "";
}

int main(int argc, const char **argv)
{
	TypeReader type_reader;
	std::string filename = ParseCommandLineParameters(argc, argv, type_reader);
	auto app = Builder::build(type_reader,filename);
	app->run();
	return 0;
}

