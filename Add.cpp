#include "Add.h"

double Add::eval(double xVal) const
{
	return (m_arguments[0]->eval(xVal) + m_arguments[1]->eval(xVal));
}
