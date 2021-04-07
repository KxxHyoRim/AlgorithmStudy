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
*   1. string ������ �Է¹ް� ���� �� getLine()
*   2. char ���� ���ҋ��� ���������� int������ //(int)'c' �����൵ �ȴٴ� ��
*   3. string �޼ҵ�� isdigit(), islower(), isupper()�� �����Ǿ� ����
*/