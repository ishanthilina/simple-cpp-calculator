#ifndef OPERATORITEM_H
#define OPERATORITEM_H

#include "Item.h"

using namespace std;
class OperatorItem : public Item
{
public:
	OperatorItem(string);
	string getOperator();

protected:
private:
	string operatorChar;
};


#endif