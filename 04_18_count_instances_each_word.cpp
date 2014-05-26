#include <assert.h>
#include <iostream>

static const int maxStack = 10;

using namespace std;

class IStack {
	
	friend class StackSeq;

public:
	IStack() : top(0) {}
	void push(int i);
	int pop();

private:
	int _arr[maxStack];
	int top;
};

class StackSeq {

public:
	StackSeq(IStack const & stack) : stack(stack), done(false) {
		cout << "StackSeq created!\n";
	}
	bool atEnd() const {
		return done;
	}
	void advance() {
		done = true;
	}
	int getNum() const {
		return 13;
	}

private:
	IStack const & stack;
	//int iCur;
	bool done;
};

class Input {
public:
	Input() {
		cout << "Input created...\n";
	}
};

class Calculator {

public:
	bool exec(const Input& input);

	const IStack& getStack() const {	// Make sure the returned member field is const
		return _stack;
	}

private:
	int cal(int n1, int n2, int token) const;

	IStack _stack;
};

bool Calculator::exec(const Input& input) {
	int token = input.token();
	bool status = false;

	if (token == tokError) {
		cout << "Unknown token...\n";
	}
	else if (token == tokNumber) {
		if (_stack.isFull()) {
			cout << "Stack is full\n";
		}
		else {
			_stack.push(input.number());
			status = true;
		}
	}
	else {
		assert(token == '+' || token == '-' || token == '*' || token == '/');

		if (_stack.isEmpty()) {
			cout << "Stack is empty...\n";
		}
		else {
			int num2 = _stack.pop();
			int num1 = _stack.isEmpty() ? num2 : _stack.pop();

			_stack.push(cal(num1, num2, token));
			status = true;
		}
	}
}

int Calculator::cal(int num1, int num2, int token) const {
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

//StackSeq::StackSeq(IStack const & stack) : iCur(0), stack(stack) {}
//
//bool StackSeq::atEnd() const {
//	return iCur == stack.top;
//}
//
//void StackSeq::advance() {
//	assert(!atEnd());	// NOT at end (if false, program abort; true will pass)
//	++iCur;
//}
//
//int StackSeq::getNum() const {
//	return stack._arr[iCur];
//}

int main() {
	Calculator cal;
	bool status;

	do {
		cout << "> ";
		Input input;
		status = cal.exec(input);

		if (status) {
			for (StackSeq seq(cal.getStack()); !seq.atEnd(); seq.advance()) {
				cout << "    " << seq.getNum() << endl;
			}
		}
	} while (status);
}