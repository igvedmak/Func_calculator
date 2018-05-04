#include "lnFunc.h"

double lnFunc::eval(double xVal) const
{
	return log(xVal);
}

void lnFunc::print(string value) const
{
	cout << LN << setprecision(4) << value << POSTFIX;
}

void lnFunc::print(shared_ptr<Expression> exp) const
{
	cout << LN;
	exp->print(VAR);
	cout << POSTFIX;
}
