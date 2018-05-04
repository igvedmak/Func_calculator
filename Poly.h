#pragma once
#include "Constant.h"
#include "Commands.h"

class Poly : public Commands
{
public:
	Poly(vector <int> numbers);
	double eval(double xVal) const;
	void print(string value) const;
	void print(shared_ptr<Expression> exp) const;
	shared_ptr<Poly> changeIt() const;
private:
	vector <int> m_coefficients;
};