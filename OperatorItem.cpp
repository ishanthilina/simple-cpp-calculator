#include "OperatorItem.h"

std::string OperatorItem::getOperator()
{
	return operatorChar;
}

OperatorItem::OperatorItem( string operatorChar )
{
	op=true;
	this->operatorChar=operatorChar;
}