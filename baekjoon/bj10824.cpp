#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string A, B, C, D;
	cin >> A >> B >> C >> D;
	cout << stoll(A + B) + stoll(C + D);


	return 0;
}
