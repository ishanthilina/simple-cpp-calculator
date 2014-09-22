#include "BinaryExpressionWithParenthesis.h"

using namespace std;


BinaryExpressionWithParenthesis::BinaryExpressionWithParenthesis( string expression,Evaluator & expressionEvaluator ): evaluator(expressionEvaluator)
{
	std::size_t prev = 0, pos;
	while ((pos = expression.find_first_of("+-*/() ", prev)) != std::string::npos)
	{
		if (pos > prev){
			OperandItem * opItem=new OperandItem(expression.substr(prev, pos-prev));
			tokens.push_back(opItem);
		}
		string operatorToken=expression.substr(pos, 1);
		//add as an operator only if it is not a space
		if(operatorToken.find(" ")==string::npos){
			OperatorItem * opItem=new OperatorItem(expression.substr(pos, 1));
			tokens.push_back(opItem);
		}
		prev = pos+1;
	}
	if (prev < expression.length())
	{
		OperandItem * opItem=new OperandItem(expression.substr(prev, std::string::npos));
		tokens.push_back(opItem);
	}
		

}

float BinaryExpressionWithParenthesis::evaluate() throw (InvalidExpressionException)
{
	return evaluator.evaluateExpression(tokens);

}

BinaryExpressionWithParenthesis::~BinaryExpressionWithParenthesis()
{
	//GC the tokens vector
	for (std::vector<Item*>::iterator it = tokens.begin() ; it != tokens.end(); ++it)
	{
		delete &(*it);
	}

}
