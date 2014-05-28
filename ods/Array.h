#ifndef ARRAY_H_

#define ARRAY_H_

#include <assert.h>

namespace ods {

template<class T>
class Array {

public:
	int length;
	Array(int len);
	Array(int len, T init);
	virtual ~Array();
	void fill(T x);
	virtual void reverse();
	static void copyOfRange(Array<T>& a, Array<T>& b, int i, int j);

	Array<T>& operator=(Array<T>& b) {
		if (a != NULL) delete[] a;
		a = b.a;
		b.a = NULL;
		length = b.length;
		return *this;
	}

	T& operator[](int i) const {
		assert(i >= 0 && i < length);
		return a[i];
	}

	T* operator+(int i) {
		return a + i;
	}

	void swap(int i, int j) {
		T tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;
	}

protected:
	T* a;
	
};

template<class T>
Array<T>::Array(int len) {
	assert(len >= 0);
	length = len;
	a = new T[len];
}

template<class T>
Array<T>::Array(int len, T init) {
	assert(len > 0);
	length = len;
	a = new T[len];
	for (int i = 0; i < len; ++i)
		a[i] = T;
}

template<class T>
Array<T>::~Array() {
	if (a != 0)
		delete[] a;
}

template<class T>
void Array<T>::reverse() {
	for (int i = 0; i < length / 2; ++i)
		swap(i, length - 1 - i);
}

template<class T>
void Array<T>::fill(T x) {
	std::fill(a, a + length, x);
}

template<class T>
void Array<T>::copyOfRange(Array<T>& a, Array<T>& b, int i, int j) {
	Array<T> tmp(j - i);
	std::copy(b.a, b.a + j - i, tmp.a);
	a.a = tmp;
}

}

#endif