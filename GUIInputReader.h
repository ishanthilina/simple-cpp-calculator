#ifndef COMMANDLINEINPUTREADER_H
#define COMMANDLINEINPUTREADER_H

#include "stdafx.h"
#include <string>
#include <iostream>
#include "Reader.h"

using namespace std;

class GUIInputReader : public Reader
{
public:
	string getNextExpression();
	void setExpression(string expression);
protected:
private:
	string expression;
};
#endif