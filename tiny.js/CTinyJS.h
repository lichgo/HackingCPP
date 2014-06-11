#ifndef CTINYJS_H

#define CTINYJS_H

#include "CScriptLex.h"

using std::vector;

class CTinyJS {
public:
	CTinyJS();
	~CTinyJS();

	void execute(const wString &code);

private:
	// lexical environment
	CScriptLex *l;

	// stack of scopes when parsing
	vector<CScriptVar*> scopes;

#ifdef TINY_JS_CALL_STACK
	// names of places when errors occur
	vector<wString> call_stack;
#endif


};

#endif