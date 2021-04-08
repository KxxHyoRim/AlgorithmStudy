#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s;
	getline(cin, s);

	for (int i = 0; i < s.length(); i++) {
		char now = s[i];
		
		/* step 1. digit or space -> display as it is */

		/* step 2. lower */
		if (islower(now))
			if (!islower(now + 13)) now -= 13; // out of lower range
			else now += 13;
		
		/* step 3. lower */
		if (isupper(now))
			if (!isupper(now + 13)) now -= 13;  // out of upper range
			else now += 13;

		cout << now;	
	}

	return 0;
}
