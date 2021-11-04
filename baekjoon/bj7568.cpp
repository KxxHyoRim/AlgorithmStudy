#include<iostream>
using namespace std;
int w[50], h[50], r[50];	//weight, hieght, rank

int main() {

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> w[i] >> h[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n ; j++) {
			if (w[i] < w[j] && h[i] < h[j]) {
				r[i]++;
			}
		}
		cout << r[i] + 1 << " ";
	}

	
	return 0;

}