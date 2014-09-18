#ifndef POSTFIXEVALUATOR_H
#define POSTFIXEVALUATOR_H

#include <vector>
#include <stack>
#include <iostream>
#include "Item.h"
#include "Evaluator.h"
#include "OperatorItem.h"
#include "OperandItem.h"

using namespace std;
class PostfixEvaluator : public Evaluator
{
public:
	float evaluateExpression(vector<Item*>);
protected:
private:
	vector<Item*> convertInfixToPostfix(vector<Item*>);
	float evaluatePostfixNotation(vector<Item*>);
};
#endif