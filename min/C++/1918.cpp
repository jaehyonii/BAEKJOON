#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void) {
	string str, result = "";
	stack <char> s;

	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') {
			s.push(str[i]);
		}
		else if (str[i] == ')'){
			while (!s.empty()) {
				char top = s.top();

				if (top == '(') {
					s.pop();
					break;
				}

				result += top;
				s.pop();
			}
		}
		else if (str[i] == '*' || str[i] == '/') {
			if (s.empty()) {
				s.push(str[i]);
			}
			else {
				while (!s.empty()) {
					char target = s.top();
					if (target == '+' || target == '-' || target == '(') {
						break;
					}
					result += target;
					s.pop();
				}
				s.push(str[i]);
			}
		}
		else if (str[i] == '+' || str[i] == '-') {
			if (s.empty()) {
				s.push(str[i]);
			}
			else {
				while (!s.empty()) {
					char target = s.top();
					if (target == '(') {
						break;
					}
					result += target;
					s.pop();
				}
				s.push(str[i]);
			}
		}
		else {
			result += str[i];
		}
	}

	while (!s.empty()) {
		char top = s.top();
		result += top;
		s.pop();
	}

	cout << result;

	return 0;
}