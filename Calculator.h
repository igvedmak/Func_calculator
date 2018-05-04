#pragma once
#include <sstream>
#include <vector>
#include <memory>
#include <iostream>
#include <string>
#include <fstream>
#include <string>
#include <istream>
#include "Expression.h"
#include "lnFunc.h"
#include "sqrtFunc.h"
#include "Constant.h"

using namespace std;

class FileLineException : public exception {
public:
	FileLineException(int lineNumber) : m_error("Error at file line: " + to_string(lineNumber)) {}
	const char * what() const noexcept {
		return  m_error.c_str();
	}
private:
	string m_error;
};


class Calculator
{
public:
	Calculator();
	void run();
	void printList() const;
	bool commandHandler(string command);
private:
	int checkEnum(const string);
	void viewHelp();
	void maxFunctionsInput();
	void checkMaximum();
	void checkRange(const double);
	void checkRange(const double, const double);
	void checkInput(const string);
	void checkInput(const string, const string);
	void oneArgument(const string);
	void zeroArgument(istringstream&, const string);
	void eval();
	void read(istringstream&);
	void resize(const int);
	template <class T>
	void binary(int, double);
	template <class T>
	void binaryChange(int, double, string);
	void throwSignBad();
	void throwSignMin();
	string line, path, m_maxFunctions, val, val2;
	int m_maxFunctionsInt , val1, m_fileLineCounter = 0, tmpVal;
	ifstream m_file;
	double val2Dou;
	bool is_ok = true;
	vector <int> valuesForPoly;
	vector <shared_ptr<Expression>> m_expressions;
};

template <class T>
void Calculator::binary(int first_func_index, double second_func_index) {
	m_expressions.push_back(make_shared<T>(m_expressions[first_func_index],m_expressions[static_cast<int>(second_func_index)]));
}

template <class T>
void Calculator::binaryChange(int first_func_index, double second_func_index, string func) {
	m_expressions.push_back(make_shared<T>(first_func_index, m_expressions[static_cast<int>(second_func_index)]));
}
