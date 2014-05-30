#ifndef DUALARRAYDEQUE_H_

#define DUALARRAYDEQUE_H_

#include "ArrayStack.h"
#include "utils.h"

namespace ods {

template<class T>
class DualArrayDeque {
public:
	DualArrayDeque();
	virtual ~DualArrayDeque();
	int size();
	T get(int i);
	T& set(int i, T x);
	virtual void add(int i, T x);
	virtual T remove(int i);
	virtual void clear();
protected:
	ArrayStack<T> front;
	ArrayStack<T> back;
	void balance();
};

template<class T>
DualArrayDeque<T>::DualArrayDeque() {}

template<class T>
DualArrayDeque<T>::~DualArrayDeque() {}

template<class T> inline
int DualArrayDeque<T>::size() {
	return front.size() + back.size();
}

template<class T> inline
T DualArrayDeque<T>::get(int i) {
	if (i < front.size())
		return front.get(front.size() - 1 - i);
	else
		return back.get(i - front.size());
}

template<class T> inline
T& DualArrayDeque<T>::set(int i, T x) {
	if (i < front.size())
		return front.set(front.size() - 1 - i, x);
	else
		return back.set(i - front.size(), x);
}

template<class T>
void DualArrayDeque<T>::add(int i, T x) {
// BUG HERE ...
	if (i <= front.size())
		front.add(front.size() - 1 - i, x);
	else
		back.add(i - front.size(), x);

	balance();
}

template<class T>
T DualArrayDeque<T>::remove(int i) {
	T x;

	if (i < front.size())
		x = front.remove(front.size() - 1 - i);
	else
		x = back.remove(i - front.size());

	balance();

	return x;
}

template<class T>
void DualArrayDeque<T>::balance() {
	if (3 * front.size() < back.size() || 3 * back.size() < front.size()) {
		int n = front.size() + back.size();
		// copy front
		int n_f = n / 2;
		Array<T>* a_f = new Array<T>(max(2 * n_f, 1));
		for (int j = 0; j < n_f; ++j)
			(*a_f)[a_f->length - 1 - j] = get(j);
		front.a = a_f;
		front.number = n_f;
		// copy back
		int n_b = n - n_f;
		Array<T>* a_b = new Array<T>(max(2 * n_b, 1));
		for (int j = 0; j < n_b; j++)
			(*a_b)[j] = get(n_f + j);
		back.a = a_b;
		back.number = n_b;
	}
}

template<class T>
void DualArrayDeque<T>::clear() {
	front.clear();
	back.clear();
}

}

#endif