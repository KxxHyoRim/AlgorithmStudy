#include <iostream>
#include<vector>
using namespace std;

int N, B, C;
vector <int> A, remain;

int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	A.resize(N); remain.resize(N);
	for (int i = 0; i < N; i++) { cin >> A[i]; }
	cin >> B >> C;

	long result = N; //정감독 부여

	for (int i = 0; i < N; i++) {
		A[i] -= B;
		if (A[i] <= 0) continue;	// 부감독 필요없음 
		result += (A[i] % C == 0) ? A[i] / C : A[i] / C + 1;
	}

	cout << result;

	return 0;
}
