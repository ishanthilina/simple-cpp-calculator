#ifndef COMMANDLINEINPUTREADER_H
#define COMMANDLINEINPUTREADER_H

#include "stdafx.h"
#include <string>
#include <iostream>
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