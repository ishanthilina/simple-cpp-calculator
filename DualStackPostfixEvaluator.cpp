#include "DualStackPostfixEvaluator.h"

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

					//get the top of the operator stack

					//remove the top item
					operatorStack.pop();

					//compute using the operator

					//get the values

					evaluateOperator(operatorStackTop,&operandStack);

					//if(operandStack.empty()){
					//	throw InvalidExpressionException("Cannot solve empty expression");
					//}

					//OperandItem * opItem1=operandStack.top();
					//float value1=opItem1->getValue();
					//operandStack.pop();

					//if(operandStack.empty()){
					//	throw InvalidExpressionException("Not enough operands to solve the expression");

					//}


					//OperandItem * opItem2=operandStack.top();
					//float value2=opItem2->getValue();
					//operandStack.pop();

					////evaluate using the operator
					//float result;
					////todo - move in to operatorItem

					//if (operatorStackTop.compare("+")==0)
					//{
					//	result=value2+value1;
					//} else if (operatorStackTop.compare("-")==0)
					//{
					//	result=value2-value1;
					//} else if (operatorStackTop.compare("*")==0)
					//{
					//	result=value2*value1;
					//}
					//else if (operatorStackTop.compare("/")==0)
					//{
					//	result=value2/value1;
					//}

					//OperandItem * opItem=new OperandItem(result);
					//operandStack.push(opItem);

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

					//get the values

					evaluateOperator(topStack->getOperator(),&operandStack);

					//if(operandStack.empty()){
					//	throw InvalidExpressionException("Cannot solve empty expression");
					//}

					//OperandItem * opItem1=operandStack.top();
					//float value1=opItem1->getValue();
					//operandStack.pop();

					//if(operandStack.empty()){
					//	throw InvalidExpressionException("Not enough operands to solve the expression");

					//}


					//OperandItem * opItem2=operandStack.top();
					//float value2=opItem2->getValue();
					//operandStack.pop();

					////evaluate using the operator
					//float result;
					////todo - move in to operatorItem
					//operatorString=topStack->getOperator();
					//if (operatorString.compare("+")==0)
					//{
					//	result=value2+value1;
					//} else if (operatorString.compare("-")==0)
					//{
					//	result=value2-value1;
					//} else if (operatorString.compare("*")==0)
					//{
					//	result=value2*value1;
					//}
					//else if (operatorString.compare("/")==0)
					//{
					//	result=value2/value1;
					//}

					//OperandItem * opItem=new OperandItem(result);
					//operandStack.push(opItem);


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

		//if(operandStack.empty()){
		//	throw InvalidExpressionException("Cannot solve empty expression");
		//}

		//OperandItem * opItem1=operandStack.top();
		//float value1=opItem1->getValue();
		//operandStack.pop();

		//if(operandStack.empty()){
		//	throw InvalidExpressionException("Not enough operands to solve the expression");

		//}


		//OperandItem * opItem2=operandStack.top();
		//float value2=opItem2->getValue();
		//operandStack.pop();

		////evaluate using the operator
		//float result;
		////todo - move in to operatorItem
		////string operatorString=item->getOperator();
		//if (op.compare("+")==0)
		//{
		//	result=value2+value1;
		//} else if (op.compare("-")==0)
		//{
		//	result=value2-value1;
		//} else if (op.compare("*")==0)
		//{
		//	result=value2*value1;
		//}
		//else if (op.compare("/")==0)
		//{
		//	result=value2/value1;
		//}

		//OperandItem * opItem=new OperandItem(result);
		//operandStack.push(opItem);

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
	//todo - move in to operatorItem
	//string operatorString=item->getOperator();
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

	OperandItem * opItem=new OperandItem(result);
	operandStack->push(opItem);

}
