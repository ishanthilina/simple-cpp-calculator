#ifndef POSTFIXEVALUATOR_H
#define POSTFIXEVALUATOR_H

#include <vector>
#include "Item.h"
#include "Evaluator.h"

using namespace std;
class PostfixEvaluator
{
public:
	float evaluateExpression(vector<Item>);
protected:
private:
};
#endif