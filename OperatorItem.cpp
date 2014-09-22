#include "OperatorItem.h"

std::string OperatorItem::getOperator() const
{
	return operatorChar;
}

OperatorItem::OperatorItem( string operatorChar )
{
	op=true;
	this->operatorChar=operatorChar;
}

bool OperatorItem::operator<=( const OperatorItem &rhs )
{
	if((operatorChar.compare("+")==0 || operatorChar.compare("-")==0) && (rhs.getOperator().compare("(")!=0 || rhs.getOperator().compare("(")!=0)){
		 return true;
	} 
	else if(operatorChar.compare("*")==0 && (rhs.getOperator().compare("*")==0 || rhs.getOperator().compare("/")==0 )){
		return true;
	} 
	else if(operatorChar.compare("/")==0 && (rhs.getOperator().compare("*")==0 || rhs.getOperator().compare("/")==0 )){
		return true;
	}
	else{
		return false;
	}
}


