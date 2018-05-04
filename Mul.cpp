#include "Mul.h"

double Mul::eval(double xVal) const
{
	return (m_arguments[0]->eval(xVal) * m_arguments[1]->eval(xVal));
}

