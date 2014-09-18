#include "PostfixEvaluator.h"

using namespace std;

float PostfixEvaluator::evaluateExpression( vector<Item*> items )
{
	items = convertInfixToPostfix(items);
	return (float)44.7;
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
			//OperatorItem* item= ((OperatorItem*)(&(*it)));

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
				

					while (*item<*topStack)
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

	return postfixVector;
}

