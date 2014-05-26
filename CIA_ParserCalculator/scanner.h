#if !defined scanner_h

#define scanner_h

#include <assert.h>

enum EToken {
	tEnd,
	tError,
	tNumber,
	tPlus,
	tMult
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

private:
	const char* _buf;
	EToken _token;
	double _number;
	int _iLook;

	void skipSpaces();
};

#endif