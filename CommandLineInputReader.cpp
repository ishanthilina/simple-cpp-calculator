#include "CommandLineInputReader.h"

using namespace std;


std::string CommandLineInputReader::getNextExpression()
{
	cout<<"Enter the expression to calculate: ";
	string expression;
	getline(cin,expression);
	return expression;
}