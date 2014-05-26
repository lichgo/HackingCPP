#if !defined stack_h

#define stack_h

static const int maxStack = 10;

class IStack {
	friend class StackSeq;

public:
	IStack() : _top(0) {};
	void push(int i);
	int pop();
	bool isFull();
	bool isEmpty();
private:
	int _arr[maxStack];
	int _top;
};


class StackSeq {
public:
	StackSeq(const IStack& stack);
	bool atEnd() const;
	void advance();
	int getNum() const;
private:
	const IStack& _stack;
	int _iCur;
};

#endif