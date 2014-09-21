#ifndef ITEM_H
#define ITEM_H

#include "stdafx.h"
#include <string>

class Item
{
public:
	bool isOperator(){
		return op;
	}
protected:
	bool op;
private:
};

#endif