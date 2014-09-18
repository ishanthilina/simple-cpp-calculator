#include <iostream>

#include "Calculator.h"
#include "Expression.h"
#include "BinaryExpression.h"
#include "PostfixEvaluator.h"
#include "Evaluator.h"



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

		evaluator = new PostfixEvaluator();

		bExpression=new BinaryExpression(expression,*evaluator);
		float result = bExpression->evaluate();

		cout<<endl<<"Result: "<<result<<endl;
	}
	

	/*


	int k;
	cin >> k;*/

	delete inputReader;
	delete evaluator;
	delete bExpression;
}


int main(){

	Calculator calc;
	calc.run();
}
