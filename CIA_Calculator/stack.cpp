#include "stack.h"
#include <assert.h>

StackSeq::StackSeq(const IStack& stack) : _stack(stack), _iCur(0) {}

bool StackSeq::atEnd() const {
	return _iCur == _stack._top;
}

void StackSeq::advance() {
	assert(!atEnd());
	++_iCur;
}

int StackSeq::getNum() const {
	//return _stack[_iCur];
	return 4;
}