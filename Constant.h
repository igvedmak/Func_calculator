#pragma once
#include <string>
#include <cstdint>
#include <sstream>
#include <vector>
#include <memory>
#include <iostream>
#include <fstream>
#include <string>
#include <istream>
using namespace std;
#define WRONG "Wrong command"
#define ENOUGH "Not enough argumens"
#define MUST_BE "Maximum must be >= "
#define OUT_RANGE "Functions out of the range"
#define REACHED "Reached to maximum number of functions"
#define BAD "Bad input"
#define BAD_ALLOC "Not enough parameters for the poly"
#define NOT_POLY "The function you chose is not a polynomial"
#define BAD_PATH "Not have a path"
#define EMPTY "Not have functions at all"
#define CHOOSE ",Do you want to delete (no ,yes): "
#define READ_OUT "The file contain much more function than your limit"
const string HELP = "eval(uate) num x - Evaluates function #num on x\n\
poly(nomial) N c0 c1 ... cN - 1 - Creates a polynomial with N coefficients\n\
rev(erse) num - Creates a polynomial with N coefficients in reverse order\n\
mul(tiply) num1 num2 - Creates a function that is the multiplication of function #num1 and function #num2\n\
add num1 num2 - Creates a function that is the sum of function #num1 and function #num2\n\
comp(osite) num1 num2 - Creates a function that is the composition of function #num1 and function #num2\n\
log N num - Log N of function #num\n\
del(ete) num - Deletes function #num from function list\n\
help - Prints this help screen\n\
resize num - Resize the amount of functions which was allocated\n\
read file.txt - reads function from the file\n\
exit - Exits the program";
const char PLUS = '+',
		MULT = '*',
		NONE = ' ',
		CARET = '^';
const string VAR = "x",
		LOG = "log",
		LN = "ln(",
		PREFIX = "(",
		POSTFIX = ")",
		SQRT = "sqrt(",
		EQUAL = " = ",
		COLON = ": ",
		MAX_FUNC = "Enter maximun functions: ",
		LIST = "This is the function list:",
		PLZ_COM = "Please enter a command (\"help\" for command list):",
	    MAX_FU = "Maximun functions is ";
enum class commandName
{
	eval,	// eval(uate)
	poly,	// poly(nomial)
	rev,
	mul,	// mul(tiply)
	add,
	comp,	// comp(osite)
	log,	// der(ivative)
	del,	// del(ete)
	help,
	resize,
	read,
	exit,
	fault
};
