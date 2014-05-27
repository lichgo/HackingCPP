#if !defined istack_h

#define istack_h

#include <assert.h>
#include <iostream>

using namespace std;

const int initSize = 1;

class IStack {
public:
	IStack();
	~IStack();
	void push(int i);
	int pop();
	int top() const;
	bool isEmpty() const;
private:
	void _grow();

	int* _arr;
	int _capacity;
	int _top;
};

IStack::IStack() : _top(0), _capacity(initSize) {
	_arr = new int[initSize];
}

IStack::~IStack() {
	cout << "Destroying a IStack...\n";
	delete[] _arr;
}

void IStack::push(int i) {
	assert(_top <= _capacity);

	if (_top == _capacity)
		_grow();

	_arr[_top] = i;

	++_top;
}

void IStack::_grow() {

	cout << " *** Grow the stack space from capacity: " << _capacity << " *** \n";

	int* newArray = new int[_capacity * 2];

	// copy the original elements to the new array
	for (int i = 0; i < _capacity; ++i) {
		newArray[i] = _arr[i];
	}

	delete[] _arr;

	_capacity *= 2;

	_arr = newArray;

}

int IStack::pop() {
	assert(_top > 0);
	return _arr[--_top];
}

int IStack::top() const {
	assert(_top > 0);
	return _arr[_top - 1];
}

bool IStack::isEmpty() const {
	assert(_top >= 0);
	return _top == 0;
}

#endif