#ifndef ARRAYSTACK_H_

#define ARRAYSTACK_H_

#include "array.h"
#include "utils.h"

namespace ods {

template<class T>
class DualArrayDeque;

template<class T>
class ArrayStack {
	friend class DualArrayDeque<T>;

public:
	ArrayStack();
	virtual ~ArrayStack();
	int size() const;
	T get(int i) const;
	T& set(int i, T x);
	virtual void add(int i, T x);
	virtual void add(T x) {
		add(size(), x);
	}
	virtual T& remove(int i);
	virtual void clear();

protected:
	Array<T>* a;
	int number;
	virtual void resize();

};

template<class T>
ArrayStack<T>::ArrayStack() : a( new Array<T>(1) ), number(0) {}

template<class T>
ArrayStack<T>::~ArrayStack() {
	delete a;
}

template<class T> inline
int ArrayStack<T>::size() const {
	return number;
}

template<class T> inline
T ArrayStack<T>::get(int i) const {
	return (*a)[i];
}

template<class T> inline
T& ArrayStack<T>::set(int i, T x) {
	T& y = (*a)[i];
	(*a)[i] = x;
	return y;
}

template<class T> 
void ArrayStack<T>::clear() {
	number = 0;
	delete a;
	a = new Array<T>(1);
}

template<class T>
void ArrayStack<T>::resize() {
	Array<T>* tmp = new Array<T>( max(2 * number, 1) );
	for (int i = 0; i < number; ++i)
		(*tmp)[i] = (*a)[i];
	a = tmp;
}

template<class T>
void ArrayStack<T>::add(int i, T x) {
	assert(i >= 0);

	if (i > number) i = number;

	if (number + 1 > (*a).length) 
		resize();

	// Move (*a)[i + 1]-[number - 1]
	for (int j = number; j > i; --j)
		(*a)[j] = (*a)[j - 1];
	(*a)[i] = x;

	number++;
}

template<class T>
T& ArrayStack<T>::remove(int i) {
	assert(i < number && i >= 0);

	T& x = (*a)[i];

	for (int j = i; j < number - 1; ++j)
		(*a)[j] = (*a)[j + 1];

	number--;

	// If too much space, cut it off
	if (a->length >= 3 * number)
		resize();

	return x;
}

}

#endif