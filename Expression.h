#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "stdafx.h"
#include <vector>
#include "InvalidExpressionException.h"

using namespace std;

class Expression
{
public:
	virtual float evaluate()=0;
protected:
private:
};

#endif
