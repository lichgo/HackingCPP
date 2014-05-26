#include "scanner.h"

#include <assert.h>
#include <iostream>

using namespace std;

Scanner::Scanner(const char* buf) : _buf(buf), _iLook(0) {
	cout << "Scanner created with " << _buf << endl;
	accept();
}

void Scanner::skipSpaces() {
	while (isspace(_buf[_iLook])) ++_iLook;
}

// find the current possible token
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
	case '.':
		_token = tNumber;
		char* p;
		// find the nearest possible number
		_number = strtod(&_buf[_iLook], &p);
		// update _iLook: the starting of the next token
		_iLook = p - _buf;
		break;
	case '\0':
		_token = tEnd;
		break;
	default:
		if (isalpha(_buf[_iLook]) || _buf[_iLook] == ' ') {
			_token = tIdent;
			_iSymbol = _iLook;

			int cLook;

			do {
				++_iLook;
				cLook = _buf[_iLook];
			} while (isalnum(cLook) || cLook == '_');

			_lenSymbol = _iLook - _iSymbol;

			if (_lenSymbol > maxSymLen)
				lenSymbol = maxSymLen;
		}
		else {
			_token = tError;
		}
		break;
	}

	return _token;
}

void Scanner::symbolName(char* strOut, int& len) {
	assert(len >= maxSymLen);
	assert(_lenSymbol <= maxSymLen);

	strncpy(strOut, &_buf[_iSymbol], _lenSymbol);
	strOut[_lenSymbol] = 0;
	len = _lenSymbol;
}