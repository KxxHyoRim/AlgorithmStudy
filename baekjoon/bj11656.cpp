#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s;
	cin >> s;

	int n = s.length();
	vector<string> v;

	for (int i = 0; i < n; i++) {
		v.push_back(s);
		s = s.substr(1);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++)
		cout << v[i] << "\n";

	return 0;
}

/**
* STL�� sort() �� Ȱ���ϱ� ���� �ڷᱸ���� vector�� ��������
* push_back()�� ���� vector�� �� string�� ����
* string�� substring()�� ���� �����Ѵ�.
*/