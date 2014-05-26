#include "input.h"
#include "stack.h"

class Calculator {
public:
	Calculator();
	bool exec(const Input& input);
	int cal(int num1, int num2, int token);
	const IStack& getStack() const;
private:
	IStack _stack;
};