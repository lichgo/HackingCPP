#include "scanner.h"

#include <iostream>

using namespace std;

Scanner::Scanner(const char* buf) : _buf(buf), _iLook(0) {
	cout << "Scanner created with " << _buf << endl;
	accept();
}

void Scanner::skipSpaces() {
	while (isspace(_buf[_iLook])) ++_iLook;
}

EToken Scanner::accept() {
	skipSpaces();

	switch (_buf[_iLook]) {
	case '+':
		_token = tPlus;
		++_iLook;
		break;
	case '*':
		_token = tMult;
		++_iLook;
		break;
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
		_token = tNumber;
		// convert char to number
		_number = atoi(&_buf[_iLook]);
		// move _iLook to the first non-digit
		while (isdigit(_buf[_iLook]))
			++_iLook;
		break;
	case '\0':
		_token = tEnd;
		break;
	default:
		_token = tError;
		break;
	}

	return _token;
}