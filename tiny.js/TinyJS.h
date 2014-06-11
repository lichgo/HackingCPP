#ifndef TINYJS_H

#define TINYJS_H
#define TINYJS_CALL_STACK

#include <vecotor>
#include "wizd_String.h"

#ifndef TRACE
#define TRACE printf
#endif

const int TINYJS_LOOP_MAX_ITERATIONS = 8192;

// Operators
enum LEX_TYPES {
	LEX_EOF = 0,
	LEX_ID = 256,
	LEX_INT,
	LEX_FLOAT,
	LEX_STR,

	LEX_EQUAL,			// ==
	LEX_TYPEEQUAL,		// ===
	LEX_NEQUAL,			// !==
	LEX_NTYPEEQUAL,		// !==
	LEX_LSHIFT,			// <<
	LEX_LSHIFTEQUAL,	// <<=
	LEX_GEQUAL,			// ==
	LEX_RSHIFT,			// >>
	LEX_RSHIFTUNSIGNED,	// >>(unsigned)
	LEX_RSHIFTEQUAL,	// >>=
	LEX_PLUSEQUAL,		// +=
	LEX_MINUSEQUAL,		// -=
	LEX_PLUSPLUS,		// ++
	LEX_MINUSMINUS,		// --
	LEX_ANDEQUAL,		// &=
	LEX_ANDAND,			// &&
	LEX_OREQUAL,		// |=
	LEX_OROR,			// ||
	LEX_XOREQUAL,		// ^=

	// Reserved words
#define LEX_R_LIST_START LEX_R_IF
	LEX_R_IF,
	LEX_R_ELSE,
	LEX_R_DO,
	LEX_R_WHILE,
	LEX_R_FOR,
	LEX_R_BREAK,
	LEX_R_CONTINUE,
	LEX_R_FUNCTION,
	LEX_R_RETURN,
	LEX_R_VAR,
	LEX_R_TRUE,
	LEX_R_FALSE,
	LEX_R_NULL,
	LEX_R_UNDEFINED,
	LEX_R_NEW,

	LEX_R_LIST_END
};

// Data types
enum SCRIPTVAR_FLAGS {
	SCRIPTVAR_UNDEFINED 	= 0,
	SCRIPTVAR_FUNCTION 		= 1,
	SCRIPTVAR_OBJECT		= 2,
	SCRIPTVAR_ARRAY			= 4,
	SCRIPTVAR_DOUBLE 		= 8,
	SCRIPTVAR_INTEGER		= 16,
	SCRIPTVAR_STRING		= 32,
	SCRIPTVAR_NULL			= 64
	SCRIPTVAR_NATIVE 		= 128,
	SCRIPTVAR_NUMERICMASK	= SCRIPTVAR_NULL | 
							  SCRIPTVAR_DOUBLE | 
							  SCRIPTVAR_INTEGER,
	SCRIPTVAR_VARTYPEMASK	= SCRIPTVAR_DOUBLE |
							  SCRIPTVAR_INTEGER |
							  SCRIPTVAR_STRING |
							  SCRIPTVAR_FUNCTION |
							  SCRIPTVAR_OBJECT |
							  SCRIPTVAR_ARRAY |
							  SCRIPTVAR_NULL
};

#define TINYJS_RETURN_VAR "return"
#define TINYJS_PROTOTYPE_CLASS "prototype"
#define TINYJS_TEMP_NAME ""
#define TINYJS_BLANK_DATA ""

// Convert wString into JS string
wString getJSString(const wString &str);

class CScriptException {
public:
	wString text;
	CScriptException(const wString &exceptionText);
};

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


};

class CScriptVar;

typedef void (*JSCallback)(CScriptVar *var, void *userdata);

class CScriptVarLink {

};

class CScriptVar {

};

class CTinyJS {
public:
	CTinyJS();
	~CTinyJS();

	void execute(const wString &code);
};


#endif