#include "parser.h"
#include <iostream>

using namespace std;

Parser::Parser(Scanner& scanner, SymbolTable& symTab) : _scanner(scanner), _symTab(symTab) {
	cout << "Parser created..\n";
}

Parser::~Parser() {
	cout << "Parser destroyed..\n";
}

Status Parser::eval() {
	cout << "Evaluating...\n";
	return QUIT;
}

//Status Parser::Parser() {
//
//}