#include "BinaryExpression.h"

using namespace std;

BinaryExpression::BinaryExpression( string expression, Evaluator & expressionEvaluator): evaluator(expressionEvaluator)
{
	istringstream buf(expression);
	for(string token; getline(buf, token, ' '); ){
	
		//check for operators
		if(token.compare("+")==0 || token.compare("-")==0 || token.compare("*")==0 || token.compare("/")==0){
			tokens.push_back(OperatorItem(token));
		}
		//else add as an operand
		else{
			tokens.push_back(OperandItem(token));
		}
	}

	evaluator = expressionEvaluator;
}

float BinaryExpression::evaluate()
{
	return 34.5;
}
