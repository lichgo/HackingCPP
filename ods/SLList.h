#ifndef SLLIST_H_

#define SLLIST_H_

#include <stdlib.h>

template<class T>
class SLList {
public:
	SLList() : head(NULL), tail(NULL), len(0) {}

	~SLList() {
		Node* cur = head;
		while (cur != NULL) {
			Node* _cur = cur->next;
			delete cur;
			cur = _cur;
		}
	}

	int size() const {
		return len;
	}

	T peek() const {
		return head->val;
	}

	bool add(T x) {
		Node* p = new Node(x);

		if (tail == NULL) {
			head = tail = p;
		}
		else {
			tail->next = p;
			tail = p;
		}

		++len;

		return true;
	}

	T pushToHead(T x) {
		Node* p = new Node(x);
		if (len == 0) {
			head = tail = p;
		}
		else {
			p->next = head;
			head = p;
		}
		len++;
		return x;
	}

	T pop() {
		if (len == 0) return NULL;
		Node* _head = head;
		T x = _head->val;
		head = head->next;
		delete _head;
		if (--len == 0) tail = NULL;
		return x;
	}

protected:
	class Node {
	public:
		T val;
		Node* next;
		Node(T x) : val(x), next(NULL) {}
	};

	Node* head;
	Node* tail;
	int len;

};

#endif