#include "BinaryExpression.h"

using namespace std;

BinaryExpression::BinaryExpression( string expression, Evaluator & expressionEvaluator): evaluator(expressionEvaluator)
{
	istringstream buf(expression);
	for(string token; getline(buf, token, ' '); ){
	
		//check for operators
		if(token.compare("+")==0 || token.compare("-")==0 || token.compare("*")==0 || token.compare("/")==0){
			OperatorItem * opItem=new OperatorItem(token);
			tokens.push_back(opItem);
		}
		//else add as an operand
		else{
			OperandItem * opItem=new OperandItem(token);
			tokens.push_back(opItem);
		}
	}

	evaluator = expressionEvaluator;
}

float BinaryExpression::evaluate() throw (InvalidExpressionException)
{
	return evaluator.evaluateExpression(tokens);
	 
}

BinaryExpression::~BinaryExpression()
{
	//GC the tokens vector
	for (std::vector<Item*>::iterator it = tokens.begin() ; it != tokens.end(); ++it)
	{
		delete &(*it);
	}
}
