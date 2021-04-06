#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string input, instruction, temp = "";
	int n, length;
	char addChar;

	cin >> input;
	cin>> n;
	length = input.length();
	
	stack<char> s1;
	stack<char> s2;

	for (int i = 0; i < length; i++) {
		s1.push(input[i]);
	}

	for (int i = 0; i < n; i++) {
		cin >> instruction;

		if (instruction == "L") {
			if (!s1.empty()) {
				s2.push(s1.top());
				s1.pop();
			}
		}

		else if (instruction == "D") {
			if (!s2.empty()) {
				s1.push(s2.top());
				s2.pop();
			}
		}

		else if (instruction == "B") {
			if (!s1.empty()) {
				s1.pop();
			}
		}

		else if (instruction == "P") {
			cin >> addChar;
			s1.push(addChar);
		}
	} // end for

	while (!s1.empty()) {
		temp += s1.top();
		s1.pop();
	}

	reverse(temp.begin(), temp.end());
	
	while (!s2.empty()) {
		temp += s2.top();
		s2.pop();
	}

	cout << temp;
}

/*
*  1. reverse(startIdx, endIdx)
*  #include<algorithm>하고 사용 -> 컴파일 에러
*  2. Stack 안쓰고 for loop -> 시간초과
*/
