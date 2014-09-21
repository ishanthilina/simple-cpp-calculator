#include "OperandItem.h"
#include <string>
#include <math.h>

using namespace std;

float OperandItem::getValue()
{
	return value;
}


OperandItem::OperandItem(float value){

	op=false;
	this->value=value;
}

OperandItem::OperandItem(string valueString)
{
	//check the given string is a valid float
	//source : http://stackoverflow.com/a/447307/1281089

	std::istringstream iss(valueString);
	float f;
	iss >> noskipws >> f;
	if (!iss.eof() || iss.fail())
	{
		throw InvalidExpressionException("\""+valueString + "\" is not a valid number");
	}
	int precision=3;
	this->value=floor((f*pow((float)10,precision)+0.5))/pow((float)10,precision);
	op=false;
}
