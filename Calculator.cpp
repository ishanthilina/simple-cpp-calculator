#include <iostream>

#include "Calculator.h"
#include "Expression.h"
#include "BinaryExpression.h"



using namespace std;

void Calculator::run()
{
	Reader * inputReader = new CommandLineInputReader();
	string expression = inputReader->getNextExpression();

	Expression * bExpression=new BinaryExpression(expression);
	//bExpression->evaluate();

	//cout<<endl<<expression<<endl;


	int k;
	cin >> k;

	delete inputReader;
	delete bExpression;
}


int main(){

	Calculator calc;
	calc.run();
}
