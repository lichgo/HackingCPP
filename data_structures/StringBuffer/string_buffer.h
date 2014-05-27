#if !defined string_buffer_h

#define string_buffer_h

#include <string.h>

const int maxBufSize = 500;

// All just dealing the pointer to the first char

class StringBuffer {
public:
	StringBuffer() : _curOffset(0) {}
	~StringBuffer() {}
	bool appendable(int len) const {
		return _curOffset + len + 1 < maxBufSize;
	}
	void add(const char* str) {
		// strcpy(insert place, the char[])
		strcpy(_buf + _curOffset, str);
		_curOffset += strlen(str) + 1;
	}
	int getOffset() const {
		return _curOffset;
	}
	bool isEqual(int offset, const char* str) const {
		return strcmp(str, _buf + offset) == 0;
	}
	const char* getString(int offset) const {
		return _buf + offset;
	}
private:
	char _buf[maxBufSize];
	int _curOffset;		// record the next empty place for inserting new string
};

#endif