#include "sqrtFunc.h"

double sqrtFunc::eval(double xVal) const
{
	return sqrt(xVal);
}

void sqrtFunc::print(string value) const
{
	cout << SQRT << setprecision(4) << value << POSTFIX;
}

void sqrtFunc::print(shared_ptr<Expression> exp) const
{
	cout << SQRT;
	exp->print(VAR);
	cout << POSTFIX;
}
