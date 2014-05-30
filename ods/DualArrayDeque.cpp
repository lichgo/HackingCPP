#include "DualArrayDeque.h"
#include <iostream>

using namespace std;

namespace ods {

	void test_dualarraydeque() {
		DualArrayDeque<int> asi;

		cout << asi.size() << '\n';	//0

		asi.add(0, 0);
		asi.add(1, 1);
		asi.add(2, 2);		//0,1,2
		cout << asi.get(0) << '\t' << asi.get(1) << '\t' << asi.get(2) << endl;

		asi.remove(1);		//0,2
		cout << asi.get(0) << '\t' << asi.get(1) << endl;

		asi.add(1, 3);		//0,3,2
		cout << asi.get(0) << '\t' << asi.get(1) << '\t' << asi.get(2) << endl;

		asi.set(0, 4);		//4,3,2
		cout << asi.get(0) << '\t' << asi.get(1) << '\t' << asi.get(2) << endl;

		cout << asi.size() << '\n';		//3

		asi.clear();

		cout << asi.size() << '\n';		//0
	}

}

//int main() {
//	// Problematic
//	ods::test_dualarraydeque();
//}