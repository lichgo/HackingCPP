#if !defined scanner_h

#define scanner_h

#include <assert.h>

enum EToken {
	tEnd,		// end
	tError,		// error
	tNumber,	// literal number
	tPlus,		// +
	tMult,		// *
	tMinus,		// -
	tDivide,	// /
	tLParen,	// (
	tRParen,	// )
	tAssign,	// =
	tIdent		// identifier
};

class Scanner {
public:
	Scanner(const char* buf);

	~Scanner();

	EToken getToken() const {
		return _token;
	}

	EToken accept();

	double number() {
		assert(_token == tNumber);
		return _number;
	}

	void symbolName(char* strOut, int& len);

private:
	const char* _buf;
	EToken _token;
	double _number;
	int _iLook;

	void skipSpaces();
};

#endif