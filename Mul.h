#pragma once
#include "Constant.h"
#include "twoArguments.h"

class Mul : public twoArguments
{
public:
	Mul(shared_ptr <Expression>  exp1, shared_ptr <Expression>  exp2) : twoArguments(exp1, exp2, MULT) {}
	double eval(double xVal) const;
};
