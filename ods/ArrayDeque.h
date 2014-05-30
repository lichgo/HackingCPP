#ifndef ARRAYDEQUE_H_

#define ARRAYDEQUE_H_

#include "Array.h"
#include "utils.h"

namespace ods {

template<class T>
class ArrayDeque {
public:
	ArrayDeque();
	virtual ~ArrayDeque();
	int size();
	T get(int i);
	T& set(int i, T x);
	virtual void add(int i, T x);
	virtual T& remove(int i);
	virtual void clear();
protected:
	Array<T>* a;
	int head;
	int number;
	void resize();
};

template<class T>
ArrayDeque<T>::ArrayDeque() : a(new Array<T>(1)), head(0), number(0) {}

template<class T>
ArrayDeque<T>::~ArrayDeque() {}

template<class T> inline
int ArrayDeque<T>::size() {
	return number;
}

template<class T> inline
T ArrayDeque<T>::get(int i) {
	assert(i >= 0 && i < number);
	return (*a)[(head + i) % a->length];
}

template<class T> inline
T& ArrayDeque<T>::set(int i, T x) {
	assert(i >= 0 && i < number);
	T& y = (*a)[(head + i) % a->length];
	(*a)[(head + i) % a->length] = x;
	return y;
}

template<class T>
void ArrayDeque<T>::add(int i, T x) {
	assert(i >= 0);

	if (i > number) i = number;

	if (number + 1 > a->length) resize();

	// copy backward
	for (int j = number - 1; j > i; --j)
		(*a)[(head + j + 1) % a->length] = (*a)[(head + j) % a->length];

	(*a)[(head + i) % a->length] = x;

	number++;
}

template<class T>
T& ArrayDeque<T>::remove(int i) {
	assert(i >= 0);

	T& y = (*a)[(head + i) % a->length];

	for (int j = i + 1; j < number; ++j)
		(*a)[(head + j - 1) % a->length] = (*a)[(head + j) % a->length];

	number--;

	if (a->length >= 3 * number) resize();

	return y;
}

template<class T>
void ArrayDeque<T>::resize() {
	Array<T>* b = new Array<T>(max(2 * number, 1));
	for (int j = 0; j < number; ++j)
		(*b)[j] = (*a)[(head + j) % a->length];
	delete a;
	a = b;
	head = 0;
}

template<class T>
void ArrayDeque<T>::clear() {
	number = 0;
	head = 0;
	Array<T>* b = new Array<T>(1);
	delete a;
	a = b;
}

}

#endif