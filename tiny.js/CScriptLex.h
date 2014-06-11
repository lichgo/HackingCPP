#ifndef CSCRIPTLEX_H

#define CSCRIPTLEX_H

class CScriptLex {
public:
	CScriptLex(const wString &input);
	CScriptLex(CScriptLex *owner, int startChar, int endChar);
	~CScriptLex(void);	// strictly ensures no function arguments

	char currCh, nextCh;
	int tk;	// type of the token that we have
	int tokenStart;	// position in the data at the beginning of the token we have here
	int tokenEnd;	// position in the data at the last char of the token we have
	int tokenLastEnd;	// position in the dta at the last char of the last token
	wString tkStr;	// data contained in the token we have here

	void match(int expected_tk);	// lexcial match wotsit
	static wString getTokenStr(int token);	// get the string representation of the given token
	void reset();	// reset the lex to restart

	wString getSubString(int pos);	// rturn a sub-string from the given position up until right now
	CScriptLex* getSubLex(int lastPosition);	// return a sub-lexer from the given position up until right now

	wString getPosition(int pos=-1);	// return a string representing the position in lines and columns of the character pos given

protected:
	char *data;
	int dataStart, dataEnd;
	bool dataOwned;

	int dataPos;

	void getNextCh();
	void getNextToken();

};

#endif