#include "SpreadsheetCell.h"
#include <sstream>

using std::ostringstream;
using std::istringstream;

namespace spreadsheet {
	SpreadsheetCell::SpreadsheetCell() : mValue(0), mString("") {}

	SpreadsheetCell::SpreadsheetCell(double initValue) : mValue(initValue), mString(doubleToString(initValue)) {}

	SpreadsheetCell::SpreadsheetCell(const string& initString) : mValue(stringToDouble(initString)), mString(initString) {}

	SpreadsheetCell::SpreadsheetCell(const SpreadsheetCell& src) : mValue(src.mValue), mString(src.mString) {}

	SpreadsheetCell& SpreadsheetCell::operator=(const SpreadsheetCell& rhs) {
		if (this != &rhs) {
			mValue = rhs.mValue;
			mString = rhs.mString;
		}
		return *this;
	}

	void SpreadsheetCell::setValue(double inValue) {
		mValue = inValue;
		mString = doubleToString(inValue);
	}

	double SpreadsheetCell::getValue() {
		return mValue;
	}

	void SpreadsheetCell::setString(const string& inString) {
		mString = inString;
		mValue = stringToDouble(inString);
	}

	string SpreadsheetCell::getString() {
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