#include <cctype>
#include <cstdlib>
#include <iostream>
#include <assert.h>

#include "input.h"

using namespace std;

Input::Input() {
	cin >> _buf;

	int c = _buf[0];

	if (isdigit(c))
		_token = tokNumber;
	else if (c == '+' || c == '*' || c == '/')
		_token = c;
	else if (c == '-') {
		if (isdigit(_buf[1]))
			_token = tokNumber;
		else
			_token = c;
	}
	else
		_token = tokError;
}

int Input::number() const {
	assert(_token == tokNumber);
	return atoi(_buf);
}