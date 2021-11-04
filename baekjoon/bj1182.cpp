#include<iostream>
using namespace std;
int arr[20];
int n, s, cnt = 0;
void subseq(int n, int sum, int choose);

int main() {

	cin >> n >> s;

	for (int i = 0; i < n; i++) { cin >> arr[i]; }
	subseq(-1, 0, 0);

	cout << cnt;

	return 0;
}

void subseq(int i, int sum, int choose) {
	i++;					

	if (i == n) {
		if (sum + arr[i] == s && choose != 0) 
			cnt++;
		return;
	}

	subseq(i, sum + arr[i], choose+1);
	subseq(i, sum, choose);
	
}

