#include "twoArguments.h"

twoArguments::twoArguments(shared_ptr <Expression>  exp1 , shared_ptr <Expression>  exp2, char c) 
	: m_c(c)
{
	m_arguments.push_back(exp1);
	m_arguments.push_back(exp2);
}
void twoArguments::print(string value) const {
	cout << PREFIX << PREFIX;
	m_arguments[0]->print(value);
	cout << POSTFIX << m_c << PREFIX;
	m_arguments[1]->print(value);
	cout << POSTFIX << POSTFIX;
}
void twoArguments::print(shared_ptr<Expression> exp) const {
	cout << PREFIX << PREFIX;
	m_arguments[0]->print(exp);
	cout << POSTFIX << m_c << PREFIX;
	m_arguments[1]->print(exp);
	cout << POSTFIX << POSTFIX;
}

