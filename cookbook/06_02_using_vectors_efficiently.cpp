#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

void f(vector<string>& vec) {
    
}

int main_0602() {
    vector<string> vec(500);
    vector<string> vec2;
    
    f(vec);
    
    vec2.reserve(500);	// better than line 13, because it doesn't initialize the slots in the buffer with anything
    
    return 0;
}