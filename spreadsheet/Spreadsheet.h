#ifndef SPREADSHEET_SPREADSHEET_H_

#define SPREADSHEET_SPREADSHEET_H_

#include "SpreadsheetImpl.h"

namespace spreadsheet {

	class SpreadsheetApplication;

	class Spreadsheet {
	public:
		Spreadsheet(const SpreadsheetApplication& theApp, int width, int height);
		Spreadsheet(const SpreadsheetApplication& theApp);
		Spreadsheet(const Spreadsheet& src);
		~Spreadsheet();

		Spreadsheet& operator=(const Spreadsheet& rhs);
		
		void setCellAt(int x, int y, const SpreadsheetCell& cell);
		SpreadsheetCell getCellAt(int x, int y);
		int getId();

	protected:
		SpreadsheetImpl* mImpl;

	};
}

#endif