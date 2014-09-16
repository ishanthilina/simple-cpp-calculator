#include <iostream>

#include "Calculator.h"


using namespace std;

void Calculator::run()
{
	Reader * inputReader = new CommandLineInputReader();
	string expression = inputReader->getNextExpression();

	cout<<endl<<expression<<endl;


	int k;
	cin >> k;

	delete inputReader;
}


int main(){

	Calculator calc;
	calc.run();
}
