#ifndef ARRAYQUEUE_H_

#define ARRAYQUEUE_H_

#include "Array.h"
#include "utils.h"

namespace ods {

template<class T>
class ArrayQueue {
public:
	ArrayQueue();
	virtual ~ArrayQueue();
	virtual bool add(T x);
	virtual T& remove();
	int size();

protected:
	Array<T>* a;
	int cur;	// keep track of the next element to remove
	int n;
	void resize();

};

template<class T>
ArrayQueue<T>::ArrayQueue() : a(new Array<T>(1)), n(0), cur(0) {}

template<class T>
ArrayQueue<T>::~ArrayQueue() {
	delete a;
}

template<class T>
bool ArrayQueue<T>::add(T x) {
	if (n + 1 > a->length) resize();
	(*a)[(cur + n) % a->length] = x;
	n++;
	return true;
}

template<class T>
T& ArrayQueue<T>::remove() {
	T& x = (*a)[cur];
	cur = (cur + 1) % a->length;
	n--;
	if (a->length >= 3 * n) resize();
	return x;
}

template<class T> inline
int ArrayQueue<T>::size() {
	return n;
}

template<class T>
void ArrayQueue<T>::resize() {
	Array<T>* b = new Array<T>(max(2 * n, 1));
	for (int i = 0; i < n; ++i)
		(*b)[i] = (*a)[(cur + i) % a->length];
	a = b;
	cur = 0;
}

}

#endif