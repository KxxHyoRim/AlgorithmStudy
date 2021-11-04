#include <iostream>
using namespace std;

int n;
int cnt = 0;
int col[15];
bool promising(int);
void queens(int i);

int main() {

	cin >> n;
	queens(0);
	cout  << cnt << endl;

	return 0;
}

void queens(int i) {

	if (promising(i)) {
		if (i == n)
			cnt++;
		else
			for (int j = 1; j <= n; j++) {
				col[i + 1] = j;
				queens(i + 1);
			}
	}
}

bool promising(int i){

	for (int chk = 1; chk < i; chk++) {
		if ((col[chk] == col[i]) ||
			abs(col[chk] - col[i]) == i - chk)
			return false;
	}
	return true;	
}
