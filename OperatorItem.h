#ifndef OPERATORITEM_H
#define OPERATORITEM_H

#include "Item.h"

using namespace std;
class OperatorItem : public Item
{
public:
	OperatorItem(string);
	string getOperator() const;
	bool operator <(const OperatorItem &rhs);

protected:
private:
	string operatorChar;
};


#endif