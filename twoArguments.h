#pragma once
#include "Arguments.h"

class twoArguments: public Arguments
{
public:
	twoArguments(shared_ptr <Expression>  exp1, shared_ptr <Expression>  exp2, char c);
	virtual void print(string value) const;
	virtual void print(shared_ptr<Expression> exp) const;
private:
	char m_c;
};