#include "Spreadsheet.h"

namespace spreadsheet {
	Spreadsheet::Spreadsheet(const SpreadsheetApplication& theApp, int width, int height) {
		mImpl = new SpreadsheetImpl(theApp, width, height);
	}

	Spreadsheet::Spreadsheet(const SpreadsheetApplication& theApp) {
		mImpl = new SpreadsheetImpl(theApp);
	}

	Spreadsheet::Spreadsheet(const Spreadsheet& src) {
		mImpl = new SpreadsheetImpl(*(src.mImpl));
	}

	Spreadsheet::~Spreadsheet() {
		delete mImpl;
		mImpl = NULL;
	}

	Spreadsheet& Spreadsheet::operator=(const Spreadsheet& rhs) {
		if (this == &rhs) return (*this);
		*mImpl = *(rhs.mImpl);	// Invoke SpreadhseetImpl's overloaded operator=
		return (*this);
	}

	void Spreadsheet::setCellAt(int x, int y, const SpreadsheetCell& cell) {
		mImpl->setCellAt(x, y, cell);
	}

	SpreadsheetCell Spreadsheet::getCellAt(int x, int y) {
		return mImpl->getCellAt(x, y);
	}

	int Spreadsheet::getId() {
		return mImpl->getId();
	}
}