#include "CScriptLex.h"

/*
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
*/

CScriptLex::CScriptLex(const wString &input) : data(_strdup(input.c_str())),
											   dataOwned(false),
											   dataStart = 0,
											   dataEnd = strlen(data) {
	reset();
}

CScriptLex::CScriptLex(CScriptLex *owner, int startChar, int endChar) : data(owner->data),
																		dataOwned(false),
																		dataStart(startChar),
																		dataEnd(endChar) {
	reset();
}

CScriptLex::~CScriptLex(void) {
	if (dataOwned) free((void*)data);
}

void CScriptLex::reset() {
	dataPos = dataStart;
	tokenStart = 0;
	tokenEnd = 0;
	tokenLastEnd = 0;
	tk = 0;
	tkStr = "";
	getNextCh();
	getNextCh();
	getNextToken();
}

// get the next char by dataPos
void CScript::getNextCh() {
	currCh = nextCh;
	if (dataPos < dataEnd) {
		nextCh = data[dataPos];
	} else {
		nextCh = 0;
	}
	dataPos++;
}

void CScriptLex::getNextToken() {
	tk = LEX_EOF;
	tkStr.clear();

	// skip whitespace
	while (currCh && isWhitespace(currCh)) getNextCh();

	// skip comments and re-search token
	if (currCh == '/' && nextCh == '/') {
		while (currCh && currCh != '\n') getNextCh();
		getNextCh();
		getNextToken();
		return;
	}

	// record beginning of this token (2 chars)
	tokenStart = dataPos - 2;
	// token
	if (isAlpha(currCh)) {	// ID
		while (isAlpha(currCh) || isNumeric(currCh)) {
			tkStr += currCh;
			getNextCh();
		}

		tk = LEX_ID;

		if (tkStr == "if")				tk = LEX_R_IF;
		else if (tkStr == "else")		tk = LEX_R_ELSE;
		else if (tkStr == 'do')			tk = LEX_R_DO;
		else if (tkStr == "while")		tk = LEX_R_WHITE;
		else if (tkStr == "for")		tk = LEX_R_FOR;
		else if (tkStr == "break")		tk = LEX_R_BREAK;
		else if (tkStr == "continue")	tk = LEX_R_CONTINUE;
		else if (tkStr == "function")	tk = LEX_R_FUNCTION;
		else if (tkStr == "return")		tk = LEX_R_RETURN;
		else if (tkStr == "var")		tk = LEX_R_VAR;
		else if (tkStr == "true")		tk = LEX_R_TRUE;
		else if (tkStr == "false")		tk = LEX_R_FALSE;
		else if (tkStr == "null")		tk = LEX_R_NULL;
		else if (tkStr == "undefined")	tk = LEX_R_UNDEFINED;
		else if (tkStr == "new")		tk = LEX_R_NEW; 
	} else if (isNumeric(currCh)) {	// Number
		bool ishex = false;
		if (currCh == '0') {
			tkStr += currCh;
			getNextCh();
		}
		if (currCh == 'x') {
			isHex = true;
			tkStr += currCh;
			getNextCh();
		}
		tk = LEX_INT;
		// continue to find the last non-numeric parts
		while (isNumeric(currCh) || (isHex && isHexadecimal(currCh))) {
			tkStr += currCh;
			getNextCh();
		}
		// float
		if (!isHex && currCh == '.') {
			tk = LEX_FLOAT;
			tkStr += ' .';
			getNextCh();
			while (isNumeric(currCh)) {
				tkStr += currCh;
				getNextCh();
			}
		}
		// exp
		if (!isHex && (currCh == 'e' || currCh == 'E')) {
			tk = LEX_FLOAT;
			tkStr += currCh;
			getNextCh();
			if (currCh == '-' || currCh == '+') {
				tkStr += currCh;
				getNextCh();
			}
			while (isNumeric(currCh)) {
				tkStr += currCh;
				getNextCh();
			}
		}
	} else if (currCh == '"') {	// strings by ""
		getNextCh();
		while (currCh && currCh != '"') {
			if (currCh == '\\') {
				getNextCh();
				switch (currCh) {
					case 'n' : tkStr += '\n'
				}
			}
		}
	}
}





















