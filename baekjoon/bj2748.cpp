#include<iostream>
using namespace std;

int n;
unsigned long long dp[91] = { 0, 1, };

unsigned long long fib(unsigned long long n) {
	if (n == 0) return dp[0];
	else if (n == 1) return dp[1];
	else if (dp[n] == 0){
		dp[n]= fib(n-1)+ fib(n-2);
	}
	return dp[n];
}


int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n;
	cout << fib(n);

	return 0;
}
