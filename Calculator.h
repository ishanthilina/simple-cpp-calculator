#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "stdafx.h"
#include <string>
#include "Reader.h"
#include "Evaluator.h"


class Calculator
{
private:
	Reader * inputReader;
	Evaluator * evaluator;
	
protected:
public:
	float run();
	Calculator(Reader *, Evaluator *);
	~Calculator();
};

#endif