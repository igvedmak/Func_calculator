#pragma once
#include "Constant.h"
#include "Expression.h"

class sqrtFunc : public Expression
{
public:
	double eval(double xVal) const;
	void print(string value) const;
	void print(shared_ptr<Expression> exp) const;

private:

};