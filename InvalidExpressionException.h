#ifndef INVALIDEXPRESSIONEXCEPTION_H
#define INVALIDEXPRESSIONEXCEPTION_H

#include <iostream>
#include <exception>

using namespace std;

class InvalidExpressionException : public exception
{
public:
	InvalidExpressionException(string);
	const char * what() const throw();
protected:
	string errorMsg;
private:
};

#endif