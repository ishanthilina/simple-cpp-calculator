#include <iostream>

#include "Calculator.h"
#include "Expression.h"
#include "BinaryExpression.h"
#include "PostfixEvaluator.h"
#include "Evaluator.h"



using namespace std;

void Calculator::run()
{
	Reader * inputReader = new CommandLineInputReader();
	string expression = inputReader->getNextExpression();

	Evaluator * evaluator = new PostfixEvaluator();

	Expression * bExpression=new BinaryExpression(expression,*evaluator);
	float result = bExpression->evaluate();

	cout<<endl<<result<<endl;


	int k;
	cin >> k;

	delete inputReader;
	delete bExpression;
}


int main(){

	Calculator calc;
	calc.run();
}
