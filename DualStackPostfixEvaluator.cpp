#include "DualStackPostfixEvaluator.h"
#include <math.h>

using namespace std;


float DualStackPostfixEvaluator::evaluateExpression( vector<Item*> tokens)
{
	stack<OperatorItem*> operatorStack;
	stack<OperandItem*> operandStack;

	//iterate the input
	for (std::vector<Item*>::iterator it = tokens.begin() ; it != tokens.end(); ++it)
	{
		//if this is an operator
		if((*it)->isOperator()){
			OperatorItem* item= static_cast<OperatorItem*>((*it));

			//if this is a right parenthesis
			string operatorString=item->getOperator();
			if(operatorString.compare(")")==0){
				
				if(operatorStack.empty()){
					throw InvalidExpressionException("Invalid number of parenthesis.");
				}
				//loop and do operations till the left parenthesis is found
				string operatorStackTop=operatorStack.top()->getOperator();
				while(!operatorStack.empty()&& operatorStackTop.compare("(")!=0){

					//remove the top item
					operatorStack.pop();

					//compute using the operator

					evaluateOperator(operatorStackTop,&operandStack);

					//get the next oprator stack item
					operatorStackTop=operatorStack.top()->getOperator();
				}

				//once the parenthesis related operations are done, a left parenthesis should be left in the 
				//operator stack
				if(operatorStack.empty()){
					throw InvalidExpressionException("Invalid number of parenthesis.");
				}
				//remove the left parenthesis
				operatorStack.pop();
				
				//skip the current loop
				continue;

			}

			

			//if the stack is empty
			if(operatorStack.empty()){
				//push the character to stack
				operatorStack.push(item);
			}
			//if the stack is not empty
			else{

				//get the top of the stack
				OperatorItem* topStack=operatorStack.top();
				//If topStack has higher precedence


				while (*item<=*topStack)
				{
					//remove the top item
					operatorStack.pop();
					
					//compute using the operator

					evaluateOperator(topStack->getOperator(),&operandStack);

					//stop the loop if the stack is empty
					if(operatorStack.empty()){
						break;
					}
					else{
						//get the next top
						topStack=operatorStack.top();
					}
				}

				//add the operator to the stack
				operatorStack.push(item);
			}

		}
		//else it's an operand
		else{
			OperandItem* value= static_cast<OperandItem*>((*it));
			operandStack.push(value);
		}
	}

	//loop and use all the operators
	while (!operatorStack.empty())
	{
		OperatorItem * remainingItem = operatorStack.top();
		operatorStack.pop();

		string op=remainingItem->getOperator();

		evaluateOperator(op,&operandStack);

	}
	


	OperandItem * returnItem = operandStack.top();
	//empty the stack
	operandStack.pop();
	if(!operandStack.empty()){
		throw InvalidExpressionException("Not a properly formatted expression.");
	}

	return returnItem->getValue();

}

void DualStackPostfixEvaluator::evaluateOperator( string operation,stack<OperandItem*>* operandStack )
{
	if(operandStack->empty()){
		throw InvalidExpressionException("Cannot solve empty expression");
	}

	OperandItem * opItem1=operandStack->top();
	float value1=opItem1->getValue();
	operandStack->pop();

	if(operandStack->empty()){
		throw InvalidExpressionException("Not enough operands to solve the expression");

	}

	OperandItem * opItem2=operandStack->top();
	float value2=opItem2->getValue();
	operandStack->pop();

	//evaluate using the operator
	float result;
	if (operation.compare("+")==0)
	{
		result=value2+value1;
	} else if (operation.compare("-")==0)
	{
		result=value2-value1;
	} else if (operation.compare("*")==0)
	{
		result=value2*value1;
	}
	else if (operation.compare("/")==0)
	{
		result=value2/value1;
	}
	else{
		//throw InvalidExpressionException("Format of the expression is invalid");
	}

	//set precision of the answer
	int precision=5;
	result=floor((result*pow((float)10,precision)+0.5))/pow((float)10,precision);

	OperandItem * opItem=new OperandItem(result);
	operandStack->push(opItem);

}
