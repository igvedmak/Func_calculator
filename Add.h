#pragma once

#include "twoArguments.h"
#include "Constant.h"
class Add : public twoArguments
{
public:
	Add(shared_ptr <Expression>  exp1, shared_ptr <Expression>  exp2) : twoArguments(exp1, exp2, PLUS) {}
	double eval(double xVal) const;
};
