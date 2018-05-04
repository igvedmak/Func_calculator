#pragma once
#include "Expression.h"
#include "Constant.h"
class lnFunc : public Expression
{
public:
	double eval(double xVal) const;
	void print(string value) const;
	void print(shared_ptr<Expression> exp) const;
};