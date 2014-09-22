#include <iostream>

#include "Calculator.h"
#include "Expression.h"
#include "BinaryExpression.h"
#include "PostfixEvaluator.h"
#include "Evaluator.h"
#include "DualStackPostfixEvaluator.h"
#include "BinaryExpressionWithParenthesis.h"



using namespace std;

float Calculator::run()
{
	float result;
	Expression * bExpression;

	string expression = inputReader->getNextExpression();

	if (expression.compare("quit")==0)
	{
		return 0;
	}

	bExpression=new BinaryExpressionWithParenthesis(expression,*evaluator);
	result = bExpression->evaluate();

	if (bExpression!=NULL)
	{
		delete bExpression;
	}

	return result;
	
}

Calculator::~Calculator()
{
	if (inputReader!=NULL)
	{
		delete inputReader;
	}

	if (evaluator!=NULL)
	{
		delete evaluator;
	}

	
}



Calculator::Calculator( Reader * reader, Evaluator * evaluator)
{
	this->inputReader=reader;
	this->evaluator=evaluator;
}

