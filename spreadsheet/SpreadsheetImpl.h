#ifndef SPREADSHEET_SPREADSHEETIMPL_H_

#define SPREADSHEET_SPREADSHEETIMPL_H_

#include "SpreadsheetCell.h"

namespace spreadsheet {

	class SpreadsheetApplication;

	class SpreadsheetImpl {
	public:
		SpreadsheetImpl(const SpreadsheetApplication& theApp, int width = kMaxWidth, int height = kMaxHeight);
		SpreadsheetImpl(const SpreadsheetImpl& src);
		~SpreadsheetImpl();

		SpreadsheetImpl& operator=(const SpreadsheetImpl& rhs);
		
		void setCellAt(int x, int y, const SpreadsheetCell& cell);
		SpreadsheetCell getCellAt(int x, int y);
		int getId();

		static const int kMaxHeight = 100;
		static const int kMaxWidth = 100;

	protected:
		inline void clearCells();
		void copyFrom(const SpreadsheetImpl& rhs);
		inline bool inRange(int val, int upper);

		int mWidth, mHeight;
		int mId;
		SpreadsheetCell** mCells;
		const SpreadsheetApplication& mTheApp;

		static int sCounter;
	};

}

#endif