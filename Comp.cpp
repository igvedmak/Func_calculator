#include "Comp.h"

double Comp::eval(double xVal) const
{
	return (m_arguments[0]->eval(m_arguments[1]->eval(xVal)));
}

void Comp::print(string value) const
{
	m_arguments[0]->print(m_arguments[1]);
}

void Comp::print(shared_ptr<Expression> exp) const
{
	auto temp = make_shared<Comp>(m_arguments[1], exp);
	m_arguments[0]->print(temp);
}
