#include "logFunc.h"

double logFunc::eval(double xVal) const
{
	return log(m_arguments[0]->eval(xVal))/log(_base);
}

void logFunc::print(string value) const
{
	cout << LOG << _base << PREFIX;
	m_arguments[0]->print(value);
	cout << POSTFIX;
}

void logFunc::print(shared_ptr<Expression> exp) const
{
	cout << LOG << _base << PREFIX;
	m_arguments[0]->print(exp);
	cout << POSTFIX;
}
