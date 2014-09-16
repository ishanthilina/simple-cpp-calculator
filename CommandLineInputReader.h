#ifndef COMMANDLINEINPUTREADER_H
#define COMMANDLINEINPUTREADER_H

#include <string>
#include "Reader.h"

using namespace std;

class CommandLineInputReader : public Reader
{
public:
	string getNextExpression();
protected:
private:
};
#endif