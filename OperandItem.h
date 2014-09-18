#ifndef OPERANDITEM_H
#define OPERANDITEM_H

#include "Item.h"
#include "InvalidExpressionException.h"
#include <string>
#include <sstream>

using namespace std;

class OperandItem : public Item
{
public:
	OperandItem(float);
	OperandItem(string);
	float getValue();

protected:
private:
	float value;
};


#endif