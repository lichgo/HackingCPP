#ifndef DLLIST_H_

#define DLLIST_H_

namespace ods {
	
template<class T>
class DLList {
public:
	DLList();
	virtual ~DLList();
	int size() { return n; }
	T get(int i);
	T set(int i, T x);
	virtual void add(int i, T x);
	virtual void add(T x) { add(n, x); }
	virtual T remove(int i);
	virtual void clear();

protected:
	struct Node {
		T val;
		Node* prev, next;
	};
	Node dummy;
	int n;
	void remove(Node* c);
	Node* addBefore(Node* c, T val);
	Node* getNode(int i);

};

template<class T>
DLList<T>::DLList() {
	dummy.next = &dummy;
	dummy.prev = &dummy;
	n = 0;
}

template<class T>
DLList<T>::DLList() {
	clear();
}

template<class T>
T DLList<T>::get(int i) {

}


}

#endif