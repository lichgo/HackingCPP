#ifndef LINEARHASHTABLE_H_

#define LINEARHASHTABLE_H_

#include <climits>
#include <iostream>
#include "Array.h"

using namespace std;

namespace ods {

extern unsigned int tab[4][256];

template<class T>
class LinearHashTable {
public:
	LinearHashTable();
	LinearHashTable(T _null, T _del);
	virtual ~LinearHashTable();
	bool add(T x);
	bool addSlow(T x);
	T remove(T x);
	T find(T x);
	int size() { return number; }
	void clear();
	void setNull(T _null) { null = _null; }
	void setDel(T _del) { del = _del;  }

private:
	static const int w = 32;
	static const int r = 8;
	Array<T> a;
	int number; // number of elements in a
	int q;		// number of non-null entries
	int d;		// a.length = 2^d
	T null, del;
	void resize();
	int hash(T x);
};

template<class T>
LinearHashTable<T>::LinearHashTable() : a(2), number(0), q(0), d(1) {}

template<class T>
LinearHashTable<T>::LinearHashTable(T _null, T _del) : null(_null), del(_del), number(0), q(0), d(1) {}

template<class T>
LinearHashTable<T>::~LinearHashTable() {}

}

#endif