#include <string>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
		if (tokens.size() == 0) return 0;

		stack<int> s;

		for (vector<string>::const_iterator iter = tokens.begin(); iter != tokens.end(); ++iter) {
			string token = *iter;

			if (token == "+" || token == "-" || token == "*" || token == "/") {
				int b = s.top();
				s.pop();
				int a = s.top();
				s.pop();

				int res;
				if (token == "+") res = a + b;
				else if (token == "-") res = a - b;
				else if (token == "*") res = a * b;
				else if (token == "/") res = a / b;

				s.push(res);
			}
			else {
				s.push(atoi(token.c_str()));
			}
		}

		return s.top();
    }
};