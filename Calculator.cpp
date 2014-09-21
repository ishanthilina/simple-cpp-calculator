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
	//while (true)
	//{
		Expression * bExpression;

		//inputReader = new CommandLineInputReader();
		string expression = inputReader->getNextExpression();

		if (expression.compare("quit")==0)
		{
			return 0;
		}

		//evaluator = new DualStackPostfixEvaluator();

		
		/*try
		{*/
			bExpression=new BinaryExpressionWithParenthesis(expression,*evaluator);
			result = bExpression->evaluate();
			cout<<endl<<"Result: "<<result<<endl;
		//}
		/*catch (InvalidExpressionException& e)
		{
			cout << endl << e.what() << '\n';
		}*/

		if (bExpression!=NULL)
		{
			delete bExpression;
		}

		return result;
		
	//}

	
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

