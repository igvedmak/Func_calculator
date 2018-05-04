#pragma once
#include <vector>
#include <math.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <memory>
#include "Constant.h"
class Expression
{
public:
	virtual double eval(double xVal) const = 0;
	virtual void print(string value) const = 0;
	virtual void print(shared_ptr<Expression> exp) const = 0;
	void rev();
protected:
	vector <shared_ptr<Expression>> m_arguments;
};