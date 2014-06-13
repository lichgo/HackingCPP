#include <cctype>
#include <sstream>

#ifdef __GNUC__
#define vscprintf_s vsnprintf
#define sprintf_s snprintf
#define _strdup strdup
#endif

// ----------- Utility ------------
bool isWhitespace(char ch) {
	return isspace(ch);
}

bool isNumeric(char ch) {
	return isdigit(ch);
}

bool isNumber(const wString &str) {
	for (size_t i = 0; i < str.size(); ++i) {
		if (!isdigit(str[i])) return false;
	}
	return true;
}

bool isHexadecimal(char ch) {
	return isdigit(ch) || (ch >= 'a' && ch <= 'f') || ( ch >= 'A' && ch <= 'F');
}

bool isAlpha(char ch) {
	return isalpha(ch) || ch == '_';
}

// Identifier should start with non-digit
bool isIDString(const char* s) {
	if (!isAlpha(*s)) return false;
	while (*s) {
		if (!isAlpha(*s) && !isdigit(*s)) return false;
		s++;
	}
	return true;
}

// allow size=0
bool isAlphaNum(const wString &str) {
	if (str.size() == 0) return true;

	return isIDString(str);
}

// TODO
wString getJSString(const wString &str) {
	ostringstream oss;

	for (size_t i = 0; i < Str.size(); ++i) {
		const char *replaceWith = "";
	}
}