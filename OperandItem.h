#ifndef OPERANDITEM_H
#define OPERANDITEM_H

#include "Item.h"

class OperandItem : public Item
{
public:
	OperandItem(float);
	float getValue();

protected:
private:
	float value;
};


#endif