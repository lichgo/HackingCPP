// Use brackets in define
#define CALL_WITH_MAX(a, b) f( (a) > (b) ? (a) : (b) )

#include <iostream>
#include <string>

using namespace std;

class GamePlayer {
private:
	enum { NumTurns = 5 };
	static const int Num = 5;	// declaration and definition
	static const string GameName = "abc";

	// Use enum to init array
	int score[NumTurns];
};

// If the compiler forces a explicit declaration
const int GamePlayer::Num;	// cannot assign value again
							// should be put in a implementation file, not a header file


// Use inline function
template<typename T>
inline void callWithMax(const T& a, const T& b) {
	f(a > b ? a : b);
}


int main() {

	// Use const
	const double AspectRatio = 1.653;
	const char* const authorName = "Jason";

	cout << authorName << endl;

	cout << GamePlayer::Num << endl;
	cout << GAmePlayer::GameName << endl;

	// Use enum to init array: enum { NUM = 3 }

	// Use inline

}