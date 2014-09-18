#ifndef BINARYEXPRESSION_H
#define BINARYEXPRESSION_H

#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include "Expression.h"
#include "Item.h"
#include "OperandItem.h"
#include "OperatorItem.h"
#include "Evaluator.h"

using namespace std;

class BinaryExpression : public Expression
{
public:
	float evaluate();
	BinaryExpression(string,Evaluator & expressionEvaluator);
protected:
	vector<Item*> tokens;
	Evaluator & evaluator;
private:
};

#endif