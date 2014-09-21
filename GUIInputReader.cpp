#include "GUIInputReader.h"

//GUIInputReader::GUIInputReader( CWnd* item )
//{
//	//this->item=item;
//}


std::string GUIInputReader::getNextExpression()
{
	
	return expression;
}

void GUIInputReader::setExpression( string expression )
{
	this->expression=expression;
}

