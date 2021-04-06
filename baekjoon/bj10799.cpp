#include <iostream>
using namespace std;

int main() {

	string input;
	cin >> input;

	int newStick = 0, oldStick = 0, curr = 0;

	for (int i = 0; i < input.length() - 1; i++) {

		if (input[i] == '(' && input[i + 1] == ')') {
			curr += (newStick * 2) + oldStick;
			oldStick += newStick;
			newStick = 0;
			i++;
		}

		else if (input[i] == '(') {	newStick++;	}

		else if (input[i] == ')') 
			if (oldStick != 0) oldStick--;
		
	}

	cout << curr;
}


