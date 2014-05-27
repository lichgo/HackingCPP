#include "calc.h"

#include <iostream>
#include <assert.h>

using namespace std;

bool Calculator::exec(const Input& input) {
	int token = input.getToken();
	bool status = false;

	//if (token == tokError) {
	//	cout << "Unknown token...\n";
	//}
	//else if (token == tokNumber) {
	//	if (_stack.isFull()) {
	//		cout << "Stack is full...\n";
	//	}
	//	else {
	//		_stack.push(input.number());
	//		status = true;
	//	}
	//}
	//else {
	//	assert(token == '+' || token == '-' || token == '*' || token == '/');

	//	if (_stack.isEmpty())
	//		cout << "Stack is empty...\n";
	//	else {
	//		int num2 = _stack.pop();
	//		int num1 = _stack.isEmpty() ? num2 : _stack.pop();

	//		_stack.push(cal(num1, num2, token));
	//		status = true;
	//	}
	//}

	return status;
}

int Calculator::cal(int num1, int num2, int token) {
	int result;

	switch (token) {
	case '+':
		result = num1 + num2;
		break;
	case '-':
		result = num1 - num2;
		break;
	case '*':
		result = num1 * num2;
		break;
	case '/':
		result = num1 / num2;
		break;
	}

	return result;
}