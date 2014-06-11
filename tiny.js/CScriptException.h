#ifndef CSCRIPTEXCEPTION_H

#define CSCRIPTEXCEPTION_H

class CScriptException {
public:
	wString text;
	CScriptException(const wString &exceptionText);
};

#endif