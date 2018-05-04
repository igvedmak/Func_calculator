#pragma once
#include "Constant.h"
#include "oneArgument.h"

class logFunc : public oneArgument
{
public:
	logFunc(int N, shared_ptr <Expression>  exp) : _base(N), oneArgument(exp) {}
	double eval(double xVal) const;
	void print(string value) const;
	void print(shared_ptr<Expression> exp) const;

private:
	int _base;
	shared_ptr <Expression> _func;
};