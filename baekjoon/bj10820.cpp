#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s;
	char c;
	int lowerN, upperN, numN, spaceN;

	while (getline(cin, s)) {

		lowerN = 0, upperN = 0, numN = 0, spaceN = 0;

		for (int i = 0; i < s.length(); i++) {
			c = s[i];

			if ('0' <= c && c <= '9') numN++;	//isdigit()
			if ('a' <= c && c <= 'z') lowerN++; //islower()
			if ('A' <= c && c <= 'Z') upperN++; //isupper()
			if (c == ' ') spaceN++;

		}

		cout << lowerN << " " << upperN << " " << numN << " " << spaceN << "\n";

	}
	return 0;
}


/** TIL
*   1. string 한줄을 입력받고 싶을 떈 getLine()
*   2. char 끼리 비교할떄는 내부적으로 int값으로 //(int)'c' 안해줘도 된다는 말
*   3. string 메소드로 isdigit(), islower(), isupper()이 구현되어 있음
*/