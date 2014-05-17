#include <string>
#include <iostream>

using namespace std;

void main_0405() {
    string s = "helloworld";
    reverse(s.begin(), s.end());
    
    std::cout << s;
}