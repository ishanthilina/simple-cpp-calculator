#ifndef WRITER_H
#define WRITER_H

#include "stdafx.h"
#include <string>

using namespace std;

class Writer
{
public:
	virtual void write(string)=0;
protected:
private:
};


#endif