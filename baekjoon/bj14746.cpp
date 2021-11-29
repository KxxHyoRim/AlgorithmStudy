#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;

int n, m, c1, c2;
vector <int> p, q, dist, cnt;
int binarySearch(int);
void findMin(int rtn, int i);


int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	// input
	cin >> n >> m >> c1 >> c2;
	p.resize(n); q.resize(m); dist.resize(n); cnt.resize(n);
	for (int i = 0; i < n; i++) {cin >> p[i];}
	for (int i = 0; i < m; i++) {cin >> q[i];}
	sort(q.begin(), q.end());
	sort(p.begin(), p.end());

	if (m == 1) {
		int min =abs( p[0] - q[0]);
		int cnt = 1;

		for (int i = 1; i < p.size(); i++) {
			int temp = abs(p[i] - q[0]);
			if (temp < min) min = temp;
			else if (temp == min) cnt++;
		}
		cout << min + abs(c1 - c2) << " " << cnt;
		return 0;
	}
	

	// start Binary Search
	for (int i = 0; i < n; i++) {
		findMin(binarySearch(i), i);
		// bs는 찾으면 찾은것, 못찾으면 left, 즉 가장 가까운 idx를 return 받음
		// findMin에서 최소거리와 개수 (dist, cnt)에 저장
	}

	int min_dist = dist[0];
	int min_cnt = cnt[0];

	for (int i = 1; i < n; i++) {

		if (dist[i] < min_dist) {
			min_dist = dist[i];
			min_cnt = cnt[i];
		}
		else if (dist[i] == min_dist) {
			min_cnt += cnt[i];
		}
	}

	cout << min_dist + abs(c1 - c2) << " " << min_cnt;

	return 0;
}

void findMin(int check, int i) {

	int t = p[i];
	int a, b, c, temp, temp_idx;

	// q의 첫 idx
	if (check == 0) {
		b = abs(q[check] - t);
		c = abs(q[check + 1] - t);
		if (b < c) {
			dist[i] = b;
			cnt[i] = 1;
		}
		else if (b == c) {
			dist[i] = b;
			cnt[i] = 2;
		}
		else {
			dist[i] = c;
			cnt[i] = 1;
		}
	}
	// 마지막 idx
	else if (check == q.size() - 1) {		// 마지막

		a = abs(q[check - 1] - t);
		b = abs(q[check] - t);
		if (a < b) {
			dist[i] = a;
			cnt[i] = 1;
		}
		else if(a==b){
			dist[i] = a;
			cnt[i] = 2;
		}
		else {
			dist[i] = b;
			cnt[i] = 1;
		}
	}
	else {		// 가운데

		a = abs(q[check - 1] - t);
		b = abs(q[check] - t);
		c = abs(q[check + 1] - t);
		
		//최대 2개가 동일하므로 a == b == c 일 가능성은 없음
		
		int count = 0;

		if (a < b) {
			temp = a;
			count = 1;
		}
		else if (a == b) {
			temp = a;
			count = 2;
		}
		else {	// b > a
			temp = b;
			count = 1;
		}

		if (temp < c) {
			dist[i] = temp;
			cnt[i] = count;
		}
		else if (temp == c) {
			dist[i] = temp;
			cnt[i] = count + 1;
		}
		else {	// temp > c
			dist[i] = c;
			cnt[i] = count;
		}
	}

}

int binarySearch(int i) {	// p의 index

	int target = p[i];

	int left = 0;
	int right = q.size() - 1;

	while (left <= right) {
		int mid = (left + right) / 2;
		int cur = q[mid];

		if (cur == target)
			return mid;			// 해당 index를 돌려줌
		else {					// 못찾음
			if (left == right)
				return left;	// 마지막까지 못찾으면 가장 가까운 index return
			if (target < cur)
				right = mid - 1;
			else
				left = mid + 1;
		}
	}

	return left;
}
