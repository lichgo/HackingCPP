#ifndef SPREADSHEET_SPREADSHEETCELL_H_

#define SPREADSHEET_SPREADSHEETCELL_H_

#include <string>

using std::string;

namespace spreadsheet {

	class SpreadsheetCell {
	public:
		friend class Spreadsheet;
		friend bool checkSpreadsheetCell(const SpreadsheetCell& cell);
		friend const SpreadsheetCell operator+(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
		friend const SpreadsheetCell operator-(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
		friend const SpreadsheetCell operator*(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
		friend const SpreadsheetCell operator/(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
		friend bool operator==(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
		friend bool operator<(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
		friend bool operator>(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
		friend bool operator!=(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
		friend bool operator<=(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
		friend bool operator>=(const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);


		SpreadsheetCell();
		SpreadsheetCell(double initValue);
		SpreadsheetCell(const string& initString);
		SpreadsheetCell(const SpreadsheetCell& src);
		SpreadsheetCell& operator=(const SpreadsheetCell& rhs);
		const SpreadsheetCell operator+(const SpreadsheetCell& rhs) const;
		SpreadsheetCell& operator+=(const SpreadsheetCell& rhs);
		SpreadsheetCell& operator-=(const SpreadsheetCell& rhs);
		SpreadsheetCell& operator*=(const SpreadsheetCell& rhs);
		SpreadsheetCell& operator/=(const SpreadsheetCell& rhs);

		void set(double inValue);
		void set(const string& inString);
		inline double getValue() const;
		inline string getString() const;

	protected:
		static string doubleToString(double inValue);
		static double stringToDouble(const string& inString);

		double mValue;
		string mString;

		mutable int mNumAccess;
	};

	bool checkSpreadsheetCell(const SpreadsheetCell& cell) {
		// As a friend, SpreadsheetCell::stringToDouble is now can be directly invoked.
		return SpreadsheetCell::stringToDouble(cell.mString) == cell.mValue;
	}
}

#endif