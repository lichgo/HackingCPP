#ifndef FASTARRAYSTACK_H_

#define FASTARRAYSTACK_H_

#include "ArrayStack.h"

namespace ods {

template<class T>
class FastArrayStack : public ArrayStack<T> {
public:
	FastArrayStack();
	virtual ~FastArrayStack();
	virtual void add(int i, T x);
	virtual T& remove(int i);
protected:
	using ArrayStack<T>::a;
	using ArrayStack<T>::number;
	virtual void resize();
};

template<class T>
FastArrayStack<T>::FastArrayStack() {}

template<class T>
FastArrayStack<T>::~FastArrayStack() {}

template<class T>
void FastArrayStack<T>::resize() {
	Array<T>* b = new Array<T>(max(2 * number, 1));
	std::copy(*a, *a + number, *b);
	a = b;
}

template<class T>
void FastArrayStack<T>::add(int i, T x) {
	assert(i >= 0);

	if (i > number) i = number;

	if (number + 1 > a->length) resize();

	std::copy_backwards((*a) + i, (*a) + number, (*a) + number + 1);

	(*a)[i] = T;

	number++;
}

template<class T>
T& FastArrayStack<T>::remove(int i) {
	assert(i < number && i >= 0);

	T& x = (*a)[i];

	std::copy((*a) + i + 1, (*a) + number, (*a) + i);

	number--;

	if (a->length >= 3 * number) resize();

	return x;
}

}

#endif