#include <string>
#include <iostream>

#include "CommandLineInputReader.h"

using namespace std;


std::string CommandLineInputReader::getNextExpression()
{
	cout<<"Enter the expression to calculate: ";
	string expression;
	cin>>expression;
	return expression;
}