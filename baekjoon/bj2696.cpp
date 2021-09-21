#include <iostream>
#include <queue>
using namespace std;

void getCenter(int num) {
	priority_queue<int> max;
	priority_queue<int, vector<int>, greater<int>> min;

	int outputNum = (num + 1) / 2;
	cout << outputNum << endl;

	//출력용 배열
	int* array = new int[(num + 1) / 2];
	int count = 0;

	int x;
	cin >> x;
	max.push(x);
	array[count++] = x;

	for (int i = 1; i < num; i++) {
		cin >> x;
		if (max.size() > min.size())
			min.push(x);
		else
			max.push(x);

		//항상 max.top()이 중앙값이 되게 유지
		if (min.top() < max.top()) {
			int maxTemp = max.top(); max.pop();
			int minTemp = min.top(); min.pop();
			max.push(minTemp);
			min.push(maxTemp);
		}

		//홀수마다 배열에 저장
		if (i % 2 == 0)
			array[count++] = max.top();
	}

	for (int i = 0; i < outputNum; i++) {
		cout << array[i] << " ";
		if (i != 0 && (i + 1) % 10 == 0)
			cout << "\n";
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int case_num, num, x;

	cin >> case_num;

	for (int i = 0; i < case_num; i++) {
		cin >> num;
		getCenter(num);
		cout << endl;
	}

	return 0;
}