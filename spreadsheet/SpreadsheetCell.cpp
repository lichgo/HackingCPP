#include "SpreadsheetCell.h"
#include <sstream>

using std::ostringstream;
using std::istringstream;

namespace spreadsheet {
	SpreadsheetCell::SpreadsheetCell() : mValue(0), mString(""), mNumAccess(0) {}

	SpreadsheetCell::SpreadsheetCell(double initValue) : mValue(initValue), mString(doubleToString(initValue)), mNumAccess(0) {}

	SpreadsheetCell::SpreadsheetCell(const string& initString) : mValue(stringToDouble(initString)), mString(initString) {}

	SpreadsheetCell::SpreadsheetCell(const SpreadsheetCell& src) : mValue(src.mValue), mString(src.mString) {}

	SpreadsheetCell& SpreadsheetCell::operator=(const SpreadsheetCell& rhs) {
		if (this != &rhs) {
			mValue = rhs.mValue;
			mString = rhs.mString;
		}
		return *this;
	}

	const SpreadsheetCell SpreadsheetCell::operator+(const SpreadsheetCell& rhs) const {
		SpreadsheetCell newCell;
		newCell.set(mValue + rhs.mValue);
		return newCell;
	}

	SpreadsheetCell& SpreadsheetCell::operator+=(const SpreadsheetCell& rhs) {
		set(mValue + rhs.mValue);
		return (*this);
	}

	SpreadsheetCell& SpreadsheetCell::operator-=(const SpreadsheetCell& rhs) {
		set(mValue - rhs.mValue);
		return (*this);
	}

	SpreadsheetCell& SpreadsheetCell::operator*=(const SpreadsheetCell& rhs) {
		set(mValue * rhs.mValue);
		return (*this);
	}

	SpreadsheetCell& SpreadsheetCell::operator/=(const SpreadsheetCell& rhs) {
		set(rhs.mValue == 0 ? 0 : mValue / rhs.mValue);
		return (*this);
	}

	void SpreadsheetCell::set(double inValue) {
		mValue = inValue;
		mString = doubleToString(inValue);
	}

	inline double SpreadsheetCell::getValue() const {
		mNumAccess++;
		return mValue;
	}

	void SpreadsheetCell::set(const string& inString) {
		mString = inString;
		mValue = stringToDouble(inString);
	}

	inline string SpreadsheetCell::getString() const {
		mNumAccess++;
		return mString;
	}

	string SpreadsheetCell::doubleToString(double inValue) {
		ostringstream ostr;
		ostr << inValue;
		return ostr.str();
	}

	double SpreadsheetCell::stringToDouble(const string& inString) {
		double tmp;
		istringstream istr(inString);
		istr >> tmp;
		if (istr.fail() || !istr.eof()) return 0;
		return tmp;
	}
}

// Define a global operator+ to enable things like SpreadsheetCell sc = 3.4 + 2.3
using spreadsheet::SpreadsheetCell;

const SpreadsheetCell operator+(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs) {
	SpreadsheetCell newCell;
	newCell.set(lhs.mValue + rhs.mValue);
	return newCell;
}

const SpreadsheetCell operator-(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs) {
	SpreadsheetCell newCell;
	newCell.set(lhs.mValue - rhs.mValue);
	return newCell;
}

const SpreadsheetCell operator*(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs) {
	SpreadsheetCell newCell;
	newCell.set(lhs.mValue * rhs.mValue);
	return newCell;
}

const SpreadsheetCell operator/(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs) {
	SpreadsheetCell newCell;
	if (rhs.mValue == 0) newCell.set(0);
	else newCell.set(lhs.mValue / rhs.mValue);
	return newCell;
}

bool operator==(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs) {
	return lhs.mValue == rhs.mValue;
}

bool operator<(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs) {
	return lhs.mValue < rhs.mValue;
}

bool operator>(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs) {
	return lhs.mValue > rhs.mValue;
}

bool operator!=(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs) {
	return !(lhs == rhs);
}

bool operator<=(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs) {
	return (lhs < rhs || lhs == rhs);
}

bool operator>=(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs) {
	return !(lhs < rhs);
}

// Defining a pointer to method or member
//SpreadsheetCell myCell;
//typedef double (SpreadsheetCell::*PtrToGet) () const;
//PtrToGet methodPtr = &SpreadsheetCell::getValue;
//(myCell.*methodPtr)()