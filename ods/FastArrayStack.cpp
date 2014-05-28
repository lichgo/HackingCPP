#include "FastArrayStack.h"
#include <iostream>

using namespace std;

namespace ods {

	void test_fastarraystack() {
		FastArrayStack<int> asi;
		cout << asi.size() << '\n';	//0

		asi.add(0);
		asi.add(1);
		asi.add(2);		//0,1,2

		asi.remove(1);	//0,2

		asi.add(1, 3);	//0,3,2
		
		asi.set(0, 4);	//4,3,2

		cout << asi.size() << '\n';		//3

		asi.clear();

		cout << asi.size() << '\n';		//0
	}

}

int main() {
	ods::test_fastarraystack();
}