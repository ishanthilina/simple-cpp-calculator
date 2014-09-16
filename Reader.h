#ifndef READER_H
#define READER_H

#include <string>

using namespace std;

class Reader
{
public:
	virtual string getNextExpression()=0;
protected:
private:
};


#endif