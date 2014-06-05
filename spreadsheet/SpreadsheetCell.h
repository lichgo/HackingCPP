#ifndef SPREADSHEET_SPREADSHEETCELL_H_

#define SPREADSHEET_SPREADSHEETCELL_H_

#include <string>

using std::string;

namespace spreadsheet {

	class SpreadsheetCell {
	public:
		SpreadsheetCell();
		SpreadsheetCell(double initValue);
		SpreadsheetCell(const string& initString);
		SpreadsheetCell(const SpreadsheetCell& src);
		SpreadsheetCell& operator=(const SpreadsheetCell& rhs);
		void setValue(double inValue);
		double getValue();
		void setString(const string& inString);
		string getString();

	protected:
		string doubleToString(double inValue);
		double stringToDouble(const string& inString);

		double mValue;
		string mString;
	};

}

#endif