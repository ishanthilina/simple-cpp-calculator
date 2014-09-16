#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <sstream>


#include "InputTokenizer.h"

using namespace std;

vector<string> InputTokenizer::getInputTokens()
{
	//read the input
	string expression;
	cout<<"Enter expression:";
	getline(cin,expression);

	//tokenize the input using spaces
	vector<string> tokens;
	istringstream buf(expression);
	for(string token; getline(buf, token, ' '); ){

		tokens.push_back(token);
	}

	return tokens;
}

InputTokenizer::InputTokenizer( char seperator)
{
	this->seperator=seperator;
}
