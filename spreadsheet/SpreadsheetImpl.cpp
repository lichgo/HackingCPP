#include "SpreadsheetImpl.h"

namespace spreadsheet {

	int SpreadsheetImpl::sCounter = 0;

	SpreadsheetImpl::SpreadsheetImpl(const SpreadsheetApplication& theApp, int width = kMaxWidth, int height = kMaxHeight) :
		mWidth(width < kMaxWidth ? width : kMaxWidth), 
		mHeight(height < kMaxHeight ? height : kMaxHeight),
		mId(sCounter++),
		mTheApp(theApp)
	{
		mCells = new SpreadsheetCell*[mWidth];
		for (int i = 0; i < mWidth; ++i)
			mCells[i] = new SpreadsheetCell[mHeight];
	}

	SpreadsheetImpl::SpreadsheetImpl(const SpreadsheetImpl& src) : mId(sCounter++), mTheApp(src.mTheApp) {

		// No need to clear, it is still an empty instance
		// clearCells();

		copyFrom(src);
	}

	SpreadsheetImpl::~SpreadsheetImpl() {
		clearCells();
		sCounter--;
	}

	SpreadsheetImpl& SpreadsheetImpl::operator=(const SpreadsheetImpl& rhs) {

		if (this == &rhs) return (*this);
		
		clearCells();

		copyFrom(rhs);

		return (*this);
	}

	void SpreadsheetImpl::setCellAt(int x, int y, const SpreadsheetCell& cell) {
		if (!inRange(x, mWidth) || !inRange(y, mHeight)) return;
		mCells[x][y] = cell;
	}

	SpreadsheetCell SpreadsheetImpl::getCellAt(int x, int y) {
		if (!inRange(x, mWidth) || !inRange(y, mHeight)) return SpreadsheetCell();
		return mCells[x][y];
	}

	int SpreadsheetImpl::getId() {
		return mId;
	}

	inline void SpreadsheetImpl::clearCells() {
		for (int i = 0; i < mWidth; ++i)
			delete[] mCells[i];
		delete[] mCells;
	}

	inline void SpreadsheetImpl::copyFrom(const SpreadsheetImpl& rhs) {
		mWidth = rhs.mWidth;
		mHeight = rhs.mHeight;

		mCells = new SpreadsheetCell*[mWidth];
		for (int i = 0; i < mWidth; ++i) {
			mCells[i] = new SpreadsheetCell[mHeight];
			for (int j = 0; j < mHeight; ++j)
				mCells[i][j] = rhs.mCells[i][j];
		}
	}
}