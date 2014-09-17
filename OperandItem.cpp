#include "OperandItem.h"
#include <string>

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
	this->value=atof(valueString.c_str());
	op=false;
}
