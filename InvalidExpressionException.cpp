#include "InvalidExpressionException.h"

const char * InvalidExpressionException::what() const throw()
{
	return this->errorMsg.c_str();
}

InvalidExpressionException::InvalidExpressionException( string errorMsg )
{
	this->errorMsg=errorMsg;
}
