#if !defined parse_h

#define parse_h

#include "scanner.h"
#include "symbol_table.h"

enum Status {
	OK,
	QUIT,
	ERROR
};

class Parser {
public:
	Parser(Scanner& scanner, SymbolTable& symTab);
	~Parser();
	Status eval();
private:
	Scanner& _scanner;
	SymbolTable& _symTab;
};

#endif