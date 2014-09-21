#ifndef EVALUATOR_H
#define EVALUATOR_H

#include "stdafx.h"
#include <vector>
#include "Item.h"

using namespace std;

class Evaluator
{
public:
	virtual float evaluateExpression(vector<Item*>)=0;
protected:
private:
};
#endif