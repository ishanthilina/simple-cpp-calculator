#include "PostfixEvaluator.h"

using namespace std;

float PostfixEvaluator::evaluateExpression( vector<Item*> items )
{
	items = convertInfixToPostfix(items);
	return (float)evaluatePostfixNotation(items);
}

vector<Item*> PostfixEvaluator::convertInfixToPostfix( vector<Item*> tokens)
{
	//vector to store the postfix string
	vector<Item*> postfixVector;

	stack<OperatorItem*> operatorStack;

	for (std::vector<Item*>::iterator it = tokens.begin() ; it != tokens.end(); ++it)
	{
		//if this is an operator
		if((*it)->isOperator()){
			OperatorItem* item= static_cast<OperatorItem*>((*it));

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
						//add it to the postfix vector
						postfixVector.push_back(topStack);

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
			postfixVector.push_back(*it);
		}

	}

	//if the stack is not empty add all the operators to the postfix vector
	while(!(operatorStack.empty())){
		postfixVector.push_back(operatorStack.top());
		operatorStack.pop();
	}

	/*for (std::vector<Item*>::iterator it = postfixVector.begin() ; it != postfixVector.end(); ++it)
	{
		if((*it)->isOperator()){
			OperatorItem* item= static_cast<OperatorItem*>((*it));
			cout<<" "<<item->getOperator();

		}
		else{
			OperandItem* value= static_cast<OperandItem*>((*it));
			cout<<" "<<value->getValue();
		}
	}*/

	return postfixVector;
}

float PostfixEvaluator::evaluatePostfixNotation( vector<Item*> postfixVector)
{
	stack<OperandItem*> operandStack;

	for (std::vector<Item*>::iterator it = postfixVector.begin() ; it != postfixVector.end(); ++it){

		//if the token is an operator
		if((*it)->isOperator()){
			OperatorItem* item= static_cast<OperatorItem*>((*it));

			//get the values

			if(operandStack.empty()){
				throw InvalidExpressionException("Cannot solve empty expression");
			}
			
			OperandItem * opItem1=operandStack.top();
			float value1=opItem1->getValue();
			operandStack.pop();

			if(operandStack.empty()){
				throw InvalidExpressionException("Not enough operands to solve the expression");

			}


			OperandItem * opItem2=operandStack.top();
			float value2=opItem2->getValue();
			operandStack.pop();

			//evaluate using the operator
			float result;
			//todo - move in to operatorItem
			string operatorString=item->getOperator();
			if (operatorString.compare("+")==0)
			{
				result=value2+value1;
			} else if (operatorString.compare("-")==0)
			{
				result=value2-value1;
			} else if (operatorString.compare("*")==0)
			{
				result=value2*value1;
			}
			else if (operatorString.compare("/")==0)
			{
				result=value2/value1;
			}

			OperandItem * opItem=new OperandItem(result);
			operandStack.push(opItem);
		}
		//if the token is an operand
		else{
			OperandItem* value= static_cast<OperandItem*>((*it));
			operandStack.push(value);
		}
		}

		OperandItem * returnItem = operandStack.top();
		//empty the stack
		operandStack.pop();
		if(!operandStack.empty()){
			throw InvalidExpressionException("Not a properly formatted expression.");
		}

		return returnItem->getValue();

	}
