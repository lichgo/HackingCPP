#include "SLList.h"
#include <iostream>

using namespace std;

namespace ods {

	void test_sllist() {
		SLList<int> list;

		cout << list.size() << endl;	//0

		list.add(0);
		list.add(1);
		list.add(2);

		cout << list.peek() << endl;	//0

		list.pop();

		cout << list.peek() << endl;	//1

		list.pushToHead(-1);

		cout << list.peek() << endl;	//-1
		
	}
	
}

int main() {
	ods::test_sllist();
}