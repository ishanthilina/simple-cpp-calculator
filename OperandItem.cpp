#include "OperandItem.h"


float OperandItem::getValue()
{
	return value;
}


OperandItem::OperandItem(float value){

	op=false;
	this->value=value;
}