#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int m, n;
unsigned long long result, lack, needs_sum, remain_people = 0;

int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> m >> n;

	vector <unsigned long long > need;
	need.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> need[i];
		needs_sum += need[i];
	}

	lack = needs_sum - m;				// 부족한 사탕수

	sort(need.begin(), need.end());

	for (int i = 0; i < n; i++) {
		remain_people = n - i;				// 남은 사람수
		unsigned long long sub = min(need[i], lack / remain_people);
		result += sub * sub;
		lack -= sub;
	}

	cout << result;
	// result를 pow(2, 64)로 나누기 안해도 됨
	// overflow의 효과 == 나머지


	return 0;
}
