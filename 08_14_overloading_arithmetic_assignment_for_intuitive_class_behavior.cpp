#include <iostream>

using namespace std;

class Balance {
	friend const Balance operator+(const Balance& lhs, const Balance& rhs);
	friend const Balance operator+(double lhs, const Balance& rhs);
	friend const Balance operator+(const Balance& lhs, double rhs);

public:
	Balance() : val_(0.0) {}
	Balance(double val) : val_(val) {}
	~Balance() {}

	Balance& operator+=(const Balance& other) {
		val_ += other.val_;
		return *this;
	}
	Balance& operator+=(double other) {
		val_ += other;
		return *this;
	}

	double getVal() const {
		return val_;
	}

private:
	double val_;
};

// Binary operators
const Balance operator+(const Balance& lhs, const Balance& rhs) {
	return Balance(lhs.getVal() + rhs.getVal());
}

const Balance operator+(double lhs, const Balance& rhs) {
	return Balance(lhs + rhs.getVal());
}

const Balance operator+(const Balance& lhs, double rhs) {
	return Balance(lhs.getVal() + rhs);
}

// Override << operator
ostream& operator<<(ostream& os, const Balance& balance) {
	os << balance.getVal() << endl;
	return os;
}


void main_0814() {
	Balance checking(500.00), savings(23.91);

	checking += 50;
	
	Balance total = checking + savings;

	cout << checking.getVal() << endl;	//550
	cout << total << endl;	//573.91
}