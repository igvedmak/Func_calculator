#pragma once

#include "twoArguments.h"
#include "Constant.h"
class Comp : public twoArguments
{
public:
	Comp(shared_ptr <Expression>  exp1, shared_ptr <Expression>  exp2) : twoArguments(exp1, exp2, NONE) {}
	double eval(double xVal) const;
	void print(string value) const;
	void print(shared_ptr<Expression> exp) const;
};