#include "Calculator.h"
#include "Add.h"
#include "logFunc.h"

#include "Comp.h"
#include "Mul.h"
#include "Poly.h"

Calculator::Calculator()
{
	m_expressions.push_back(make_shared<lnFunc>());
	m_expressions.push_back(make_shared<sqrtFunc>());
}

void Calculator::run()
{
	string command;
	cin.exceptions(istream::failbit | istream::badbit);

	is_ok = false;
	while (!is_ok) {
		try {
			cout << MAX_FUNC;
			maxFunctionsInput();
			is_ok = true;
		}
		catch (out_of_range e) {
			cout << e.what() << endl;
		}
		catch (domain_error e) {
			cout << e.what() << endl;
		}
	}

	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	while (true)
	{
		printList();
		auto saver = m_expressions[0].use_count();
		getline(cin, command);
		is_ok = commandHandler(command);
	}
}
void Calculator::maxFunctionsInput() {
	cin >> m_maxFunctions;
	for (int i = 0; i< static_cast<int>(m_maxFunctions.size()); i++) {
		if (isdigit(m_maxFunctions[i]))
			continue;
		else
			throwSignBad();
	}
	m_maxFunctionsInt = stoi(m_maxFunctions);
	if (m_maxFunctionsInt < 2)
		throwSignMin();	
}
void Calculator::throwSignBad() {
	throw domain_error(BAD);
}
void Calculator::throwSignMin() {
	string errorM = MUST_BE + to_string(m_expressions.size());
	throw out_of_range(errorM.c_str());
}
void Calculator::printList() const
{
	cout << LIST << endl;
	for (int i = 0; i < static_cast<int>(m_expressions.size()); i++)
	{
		cout << i << COLON;
		m_expressions[i]->print(VAR);
		cout << endl;
	}
	cout << PLZ_COM << endl << MAX_FU << m_maxFunctionsInt << endl << endl;
}
void Calculator::checkMaximum() {
	if (m_expressions.size() == m_maxFunctionsInt)
		throw out_of_range(REACHED);
}
void Calculator::checkRange(const double index) {
	if (index < 0 || m_expressions.size() <= index)
		throw out_of_range(OUT_RANGE);
}
void Calculator::checkRange(const double index, const double index2) {
	if (index < 0 || m_expressions.size() <= index)
		throw out_of_range(OUT_RANGE);
	checkRange(index2);
}
void Calculator::checkInput(const string val) {
	if (isalpha(val[0]))
		throwSignBad();
	val1 = stoi(val);
}
void Calculator::checkInput(const string val, const string val2) {
	if (isalpha(val[0]) || isalpha(val2[0]) || stoi(val) < 0 || stoi(val2) < 0)
		throwSignBad();
	checkInput(val);
	val2Dou = stoi(val2);
}
void Calculator::oneArgument(const string commandName) {
	if (commandName == "help")
		viewHelp();
	else if (commandName == "exit")
		exit(EXIT_SUCCESS);
	else if (commandName != "help" && commandName != "exit")
		throw domain_error(WRONG);
}
void Calculator::zeroArgument(istringstream &cmd,const string commandName) {
	try {
		oneArgument(commandName);
	}
	catch (domain_error e) {
		cout << e.what() << endl;
	}
}
void Calculator::resize(const int val1) {
	if (val1 < m_maxFunctionsInt) {
		string errorM = MUST_BE + to_string(m_maxFunctionsInt);
		string chooise;
		while (chooise != "yes" && chooise != "no") {
			cout << errorM;
			cout << CHOOSE;
			cin >> chooise;
		}
		if (chooise == "yes") {
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			checkRange(val1);
			m_expressions.erase(m_expressions.begin() + val1);
			if (m_expressions.size() == 0)
				throw length_error(EMPTY);
		}
		else
			throw out_of_range(errorM.c_str());
	}
	m_maxFunctionsInt = val1;
}
int Calculator::checkEnum(const string command) {
	if (command == "eval" || command == "mul" || command == "add" || command == "comp" || command == "log")
		return 0;
	if (command == "poly")
		return 1;
	if (command == "rev" || command == "del" || command == "resize")
		return 2;
	if (command == "read")
		return 4;
	else
		return 3;
}
void Calculator::eval() {
	checkRange(val1);
	string value = to_string(val2Dou);
	value.erase(value.find_last_not_of('0') + 2, string::npos);
	m_expressions[val1]->print(value);
	cout << EQUAL << m_expressions[val1]->eval(val2Dou) << endl;
}

bool Calculator::commandHandler(string command)
{
	istringstream cmd(command);
	string commandName;
	try {
		cmd.exceptions(cmd.failbit | cmd.badbit);
		cmd >> commandName;
		switch (checkEnum(commandName))
		{
		case 0:
			checkMaximum();
			cmd >> val >> val2;
			checkInput(val, val2);
			if (commandName == "eval")
				eval();
			else {
				checkRange(val1, val2Dou);
				if (commandName == "mul")
					binary<Mul>(val1, val2Dou);
				else if (commandName == "add")
					binary<Add>(val1, val2Dou);
				else if (commandName == "comp")
					binary<Comp>(val1, val2Dou);
				else if (commandName == "log")
					binaryChange<logFunc>(val1, val2Dou, commandName);
			}
			break;
		case 1:
			checkMaximum();
			cmd >> val;
			checkInput(val);
			for (int i = 0; i < val1; i++){
				cmd >> tmpVal;
				valuesForPoly.push_back(tmpVal);
			}
			m_expressions.push_back(make_shared<Poly>(valuesForPoly));
			valuesForPoly.clear();
			break;
		case 2:
			cmd >> val;
			checkInput(val);
			if (commandName == "del")
			{
				checkRange(val1);
				m_expressions.erase(m_expressions.begin() + val1);
				if (m_expressions.size() == 0)
					throw length_error(EMPTY);
			}
			if (commandName == "rev") {
					checkMaximum();
					auto poly = dynamic_pointer_cast<Poly>(m_expressions[val1]);
					if (poly)
						m_expressions.push_back(poly->changeIt());
					else
						throw domain_error(NOT_POLY);
			}
			else if (commandName == "resize")
				resize(val1);
			break;
		case 3:
			zeroArgument(cmd, commandName);
			break;
		case 4:
			read(cmd);
			break;
		}
	}
	catch (istream::failure e) {
		cout << ENOUGH << endl;
		return false;
	}
	catch (domain_error e) {
		cout << e.what() << endl;
		return false;
	}
	catch (out_of_range e) {
		cout << e.what() << endl;
		return false;
	}
	catch (invalid_argument e) {
		cout << e.what() << endl;
		return false;
	}
	catch(length_error e){
		cout << e.what() << endl;
		exit(EXIT_SUCCESS);
	}
	catch (FileLineException e) {
		cout << e.what() << endl;
		return false;
	}
	catch (...) {
		cout << BAD_ALLOC << endl;
		return false;
	}
	return true;
}

void Calculator::viewHelp(){
	cout << HELP;
}
void Calculator::read(istringstream& cmd) {
	auto lastFunctions = m_expressions;
	try {
		cmd >> path;
	}
	catch (...) {
		throw invalid_argument(BAD_PATH);
	}

	if (path != "continue") {
		//m_file.exceptions(ifstream::failbit);
		try {
			m_file.open(path);
			m_fileLineCounter = 1;
		}
		catch (ifstream::failure e) {
			throw invalid_argument(CANT_OPEN);
		}
	}

	while (!m_file.eof() && getline(m_file, line)) {
		if (!line.empty()) {
			if (!commandHandler(line)) {
				cout << ERROR << m_fileLineCounter << endl;
				while (chooise != "yes" && chooise != "no") {
					cout << DO;
					cin >> chooise;
					if (chooise == "no") {
						m_expressions = lastFunctions;
						closefile(m_file, m_fileLineCounter);
					}
					else {
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						closefile(m_file, m_fileLineCounter);
					}
				}
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}
		m_fileLineCounter++;
	}
	m_file.close();
}
void closefile(ifstream & m_file, int m_fileLineCounter) {
	m_file.close();
	throw FileLineException(m_fileLineCounter);
}


