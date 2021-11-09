#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int t, n, tmp1, tmp2, cnt;
void TestCase();

int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> t;
	for (int i = 0; i < t; i++) { TestCase(); }

	return 0;
}

void TestCase() {

	cnt = 0;
	vector <pair<int, int>> vec;

	cin >> n;
	vec.resize(n);

	for (int i = 0; i < n; i++)
		cin >> vec[i].first >> vec[i].second;

	sort(vec.begin(), vec.end());	
	// 첫번째 기준 : vec[i].first, 두번째 기준 : vec[i].second


	int s2_curr, s2_min = vec[0].second;

	for (int i = 0; i < n; i++) {
		s2_curr = vec[i].second;
		if (s2_min > s2_curr) {
			cnt++;
			s2_min = s2_curr;
		}
	}

	cout << cnt+1 << endl;	// + 1 :첫번째 사람은 무조건 합격
}
