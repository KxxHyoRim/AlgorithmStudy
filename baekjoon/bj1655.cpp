#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, x;
	priority_queue<int> max;
	priority_queue<int, vector<int>, greater<int>> min;
	cin >> n;

	cin >> x;
	max.push(x);
	cout << x << endl;

	for (int i = 1; i < n; i++) {
		cin >> x;
		if (max.size() > min.size())
			min.push(x);
		else
			max.push(x);

		if (min.top() < max.top()) {
			int maxTemp = max.top(); max.pop();
			int minTemp = min.top(); min.pop();
			max.push(minTemp);
			min.push(maxTemp);
		}

		cout << max.top() << "\n";

	}

	return 0;
}
