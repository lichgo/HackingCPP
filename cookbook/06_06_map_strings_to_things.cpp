#include <iostream>
#include <map>
#include <string>

using namespace std;

template<typename V, typename K>
void printer(const map<K, V>& m) {
	for (typename map<K, V>::const_iterator iter = m.begin(); iter != m.end(); ++iter) {
		cout << "KEY: " << iter->first << " VALUE: " << iter->second << endl;
	}
	cout << "----------------------" << endl;
}

int main_0606() {
	map<string, string> toStr;

	toStr["Monday"] = "MON";
	toStr["Tuesday"] = "TUE";
	toStr["Wednesday"] = "WED";
	toStr["Wednesday"] = "WWW";

	// insert
	toStr.insert(make_pair("Thursday", "THU"));
	toStr.insert(pair<string, string>("Friday", "FRI"));

	printer(toStr);

	//toStr.erase(toStr.find("Sunday")); // error
	toStr.erase(toStr.find("Friday"));

	printer(toStr);

	return 0;
}