#include "builder.h"
#include "consolereader.h"
#include "filereader.h"
#include "typedetector.h"
#include "multiplier.h"
#include "textdecoder.h"
#include "textencoder.h"
#include "consolewriter.h"


using namespace std;


unique_ptr<App> Builder::build(const TypeReader &a_type_reader, const std::string a_filename)
{
	unique_ptr<App> app = make_unique<App>();

	IReader *pReader;
	if(a_type_reader == CONSOLE_READER)
		pReader = new ConsoleReader();
	else
		pReader = new FileReader(a_filename);
	TypeDetector *pTypeDetector = new TypeDetector();
	TextDecoder *pTextDecoder = new TextDecoder();
	Multiplier *pMultiplier = new Multiplier();
	ConsoleWriter *pWriter = new ConsoleWriter();
	TextEncoder *pTextEncoder = new TextEncoder();
	
	app->setReader(pReader);
	app->setTypeDetector(pTypeDetector);
	app->addDecoder(pTextDecoder);
	app->setMultiplier(pMultiplier);
	app->addEncoder(pTextEncoder);
	app->setWriter(pWriter);

	pReader->setTypeDetector(pTypeDetector);
	pTypeDetector->setMultiplier(pMultiplier);
	pTextEncoder->setWriter(pWriter);
	pTypeDetector->setTextDecoder(pTextDecoder);
	pTextDecoder->setMultiplier(pMultiplier);
	pMultiplier->setTextEncoder(pTextEncoder);
	pMultiplier->setWriter(pWriter);

	return app;
}