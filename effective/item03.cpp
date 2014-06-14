#include <iostream>

using namespace std;

class TextBlock {
private:
	static const string text;
public:
	const char& operator[](size_t pos) const {
		cout << "Const member function" << endl;
		return text[pos];
	}
	char operator[](size_t pos) {
		cout << "non-const member function" << endl;
		return text[pos];
	}
	int getInt() {
		cout << "get int" << endl;
		return 3;
	}
};

// no static, but const here
const string TextBlock::text = "hello";

int main() {
	// Compare array and pointer
	char str[] = "Hello";				// str is originally a pointer
	for (int i = 0; i < 6; ++i) {
		cout << *(str + i) << endl;
		str[i] += 1;					// mutable
	}
	cout << str << endl;

	// Using const
	char* p = str;				// non-const pointer, non const data
	const char* p = str;		// non-const pointer, const data
	char* const p = str;		// const pointer, non-const data
	const char* const p = str;	// const pointer, const data

	TextBlock tb1;
	tb1[1];
	const TextBlock tb2;
	tb2[1];
	tb2.getInt();

}







