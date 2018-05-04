#include "Poly.h"

Poly::Poly(vector <int> numbers)
{
	//for (auto& num : numbers)
	//	m_coefficients.push_back(num);
	m_coefficients = numbers;
}

double Poly::eval(double xVal) const
{

	double val = 0;
	for (int xPow = 0; xPow < int(m_coefficients.size()); xPow++)
		val += m_coefficients[xPow] * pow(xVal, xPow);

	return val;
}

void Poly::print(string value) const
{
	for (int xPow = static_cast<int>(m_coefficients.size()) - 1; xPow >= 0; xPow--)
	{
		if (m_coefficients[xPow] != 0)
		{
			cout << m_coefficients[xPow] <<MULT << value << CARET << xPow;
			if (xPow != 0)
				cout << NONE << PLUS << NONE;
		}
	}
}

void Poly::print(shared_ptr<Expression> exp) const
{
	for (int xPow = static_cast<int>(m_coefficients.size()) - 1; xPow >= 0; xPow--)
	{
		if (m_coefficients[xPow] != 0)
		{
			cout << m_coefficients[xPow] << MULT;
			exp->print(VAR);
			cout << CARET << xPow;
			if (xPow != 0)
				cout << NONE << PLUS << NONE;
		}
	}
}

shared_ptr<Poly> Poly::changeIt() const {
	auto rev_coeffs = m_coefficients;
	reverse(rev_coeffs.begin(), rev_coeffs.end());
	return std::make_shared<Poly>(rev_coeffs);
}