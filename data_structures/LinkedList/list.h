#if !defined list_h

#define list_h

#include <iostream>

using namespace std;

class Link {
public:
	Link(Link* pNext, int id) : _pNext(pNext), _id(id) {}
	~Link() {
		//delete _pNext;
	}
	Link* next() const {
		return _pNext;
	}
	int id() const {
		return _id;
	}
private:
	int _id;
	Link* _pNext;
};

class List {
public:
	List() : _pHead(0) {}
	~List();
	void add(int id);
	const Link* getHead() const {
		return _pHead;
	}
private:
	Link* _pHead;
};

List::~List() {
	cout << " *** Destroying the list ... ***\n";

	// Option 1: deleting elements in a loop
	/*
	while (_pHead != 0) {
		Link* current = _pHead;
		_pHead = _pHead->next();
		delete current;
	}
	*/

	// Option 2: Make use of Link's destructor and do it recursively
	delete _pHead;
}

void List:: add(int id) {
	// Add new link in front of the pHead
	Link* link = new Link(_pHead, id);
	_pHead = link;
}

#endif