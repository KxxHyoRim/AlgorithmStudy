#include <iostream>
#include <queue>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	queue<int> q;

	int n, num;
	string inst;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> inst;
		
		if (inst == "push") {
			cin >> num;
			q.push(num);
		}
		
		else if (inst == "pop")
			if (q.empty()) cout << "-1\n";
			else {
				cout << q.front() << "\n";
				q.pop();
			}

		else if (inst == "size") 
			cout << q.size() << "\n";
		
		else if (inst == "empty") 
			if (q.empty()) cout << "1\n";
			else cout << "0\n";
		

		else if (inst == "front") 
			if (q.empty()) cout << "-1\n";
			else cout << q.front() << "\n";
		

		else if (inst == "back") {
			if (q.empty()) cout << "-1\n";
			else cout << q.back() << "\n";
		}
	}
}

/* 1. queue stl 사용
*  2.endl 보다는 "\n"이 훨씬 빠름
*  3. if -else 와 if 간의 속도차이는 없는것같음(둘다 0ms)
*/
