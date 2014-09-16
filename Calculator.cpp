#include <iostream>
#include <string>
#include <vector>

#include "InputTokenizer.h"
#include "IntermediateFormConverter.h"
#include "PostfixConverter.h"

using namespace std;

class Calculator
{
public:
	void run();
protected:
private:
};

void Calculator::run()
{
	//get the input tokens
	char inputSeperator=' ';
	InputTokenizer inputTokenizer(inputSeperator);
	vector<string> tokens=inputTokenizer.getInputTokens();

	//test
	/*cout<<"tokens: "<<endl;
	for (vector<string>::iterator it = tokens.begin() ; it != tokens.end(); ++it){
		cout << ' ' << *it<< endl;
	}*/
	//

	//create the postfix notation

	IntermediateFormConverter * converter=new PostfixConverter();
	converter->convert(tokens);
	//converter.convert(tokens);

	int k;
	cin>>k;

	delete converter;
	
	
}

int main(){
	Calculator calc;
	calc.run();
}
