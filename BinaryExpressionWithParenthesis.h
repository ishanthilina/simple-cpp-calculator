#ifndef BINARYEXPRESSIONWITHPARENTHESIS_H
#define BINARYEXPRESSIONWITHPARENTHESIS_H

#include "stdafx.h"
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

class BinaryExpressionWithParenthesis : public Expression
{
public:
	float evaluate() throw (InvalidExpressionException);
	BinaryExpressionWithParenthesis(string,Evaluator&);
	~BinaryExpressionWithParenthesis();
protected:
	vector<Item*> tokens;
	Evaluator & evaluator;
private:
};

#endif