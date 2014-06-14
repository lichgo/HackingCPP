#include <iostream>

using namespace std;

class Score {

public:
	Score() : score_(0) {}
	Score(int i) : score_(i) {}

	// prefix: ++i, add then use => ++Score
	Score& operator++() {
		++score_;
		return *this;
	}

	// postfix: i++, use then add => Score++
	const Score operator++(int) {	// at runtime, [int] is always zero
		Score tmp(*this);
		++(*this);	// Take advantage of the overloaded prefix operator
		return tmp;
	}

	int getScore() const {
		return score_;
	}

private:
	int score_;
};

void main_0813() {
	Score player1(50);

	player1++;
	++player1;
}