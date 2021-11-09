#include<iostream>
#include<queue>
using namespace std;

int t, n, tmp1, tmp2, cnt;
void TestCase();

int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> t;

	for (int i = 0; i < t; i++) {
		TestCase();
	}


	return 0;
}

void TestCase() {

	cnt = 0;

	typedef pair<int, int> score;

	struct cmp {
		// 첫번째 성적 기준으로 내림차순 정렬
		bool operator()(score& a, score& b) {
			return a.first > b.first;
		}
	};

	priority_queue<score, vector<score>, cmp> pq;
	cin >> n;


	for (int i = 0; i < n; i++) {
		cin >> tmp1 >> tmp2;
		pq.push({ tmp1, tmp2 });
	}

	int s2_curr, s2_min = pq.top().second;

	while (!pq.empty()) {
		s2_curr = pq.top().second;
		pq.pop();

		if (s2_min > s2_curr) {
			cnt++;
			s2_min = s2_curr;
		}
	}

	
	cout << cnt+1 << endl;	// + 1 :첫번째 사람은 무조건 합격
}
