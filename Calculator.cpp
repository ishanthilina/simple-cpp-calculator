#include <iostream>

#include "Calculator.h"
#include "Expression.h"
#include "BinaryExpression.h"
#include "PostfixEvaluator.h"
#include "Evaluator.h"
#include "DualStackPostfixEvaluator.h"
#include "BinaryExpressionWithParenthesis.h"



using namespace std;

void Calculator::run()
{
	Reader * inputReader;
	Evaluator * evaluator;
	Expression * bExpression;
	while (true)
	{
		inputReader = new CommandLineInputReader();
		string expression = inputReader->getNextExpression();

		if (expression.compare("quit")==0)
		{
			return;
		}

		evaluator = new DualStackPostfixEvaluator();

		
		try
		{
			bExpression=new BinaryExpressionWithParenthesis(expression,*evaluator);
			float result = bExpression->evaluate();
			cout<<endl<<"Result: "<<result<<endl;
		}
		catch (InvalidExpressionException& e)
		{
			cout << endl << e.what() << '\n';
		}
		
	}

	if (inputReader!=NULL)
	{
		delete inputReader;
	}

	if (evaluator!=NULL)
	{
		delete evaluator;
	}

	if (bExpression!=NULL)
	{
		delete bExpression;
	}
}


int main(){

	Calculator calc;
	calc.run();
}
