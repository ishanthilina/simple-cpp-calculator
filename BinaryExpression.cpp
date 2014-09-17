#include "BinaryExpression.h"

using namespace std;

BinaryExpression::BinaryExpression( string expression)
{
	
	
	istringstream buf(expression);
	for(string token; getline(buf, token, ' '); ){
	
		//check for operators
		if(token.compare("+")==0 || token.compare("-")==0 || token.compare("*")==0 || token.compare("/")==0){
			cout<<"Operator: "<<token<<endl;
			//tokens.push_back(OperatorItem(token));
			cout<<"Operator: "<<token<<endl;

		}
		//else add an operand
		else{
			cout<<"Operand: "<<token<<endl;
		}

		//tokens.push_back(token);
	}
	
}

float BinaryExpression::evaluate()
{
	return 34.5;
}
