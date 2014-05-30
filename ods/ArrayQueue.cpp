#include "ArrayQueue.h"
#include <iostream>

using namespace std;

namespace ods {

	void test_arrayqueue() {
		ArrayQueue<int> asi;

		cout << asi.size() << '\n';	//0

		asi.add(0);
		asi.add(1);
		asi.add(2);		//0,1,2

		asi.remove();	//0,1

		asi.add(3);
		asi.add(4);
		asi.add(5);
		asi.add(6);		//0,1,3,4,5,6

		asi.remove();
		asi.remove();	//0,1,3,4

		cout << asi.size() << '\n';		//4

	}

}