#include <iostream>
#include <string>

using namespace std;

template<typename T, typename N = short>	// default type
class TreeNode {
public:
	TreeNode(const T& val) : val_(val), left_(NULL), right_(NULL) {}

	~TreeNode() {
		delete left_;
		delete right_;
	}

	const T& getVal() const {
		return val_;
	}

	void setVal(const T& val) {
		val_ = val;
	}

	void appendChild(TreeNode<T>* p) {
		const T& other = p->val_;

		if (other > val_)
			if (right_)
				right_->appendChild(p);
			else
				right_ = p;
		else
			if (left_)
				left_->appendChild(p);
			else
				left_ = p;
	}

	const TreeNode<T>* getLeft() {
		return left_;
	}

	const TreeNode<T>* getRight() {
		return right_;
	}

private:
	T val_;
	TreeNode<T>* left_;
	TreeNode<T>* right_;
};

void main_0811() {
	TreeNode<string> node1("5");
	TreeNode<string> node2("6");
	TreeNode<string> node3("1");

	node1.appendChild(&node2);
	node1.appendChild(&node3);
}