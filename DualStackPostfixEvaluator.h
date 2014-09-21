#ifndef DUALSTACKPOSTFIXEVALUATOR_H
#define DUALSTACKPOSTFIXEVALUATOR_H

#include "stdafx.h"
#include <vector>
#include <stack>
#include <iostream>
#include "Item.h"
#include "Evaluator.h"
#include "OperatorItem.h"
#include "OperandItem.h"
#include "InvalidExpressionException.h"

using namespace std;
class DualStackPostfixEvaluator : public Evaluator
{
public:
	float evaluateExpression(vector<Item*>);
protected:
private:
	void evaluateOperator(string operation,stack<OperandItem*>*);
};
#endif