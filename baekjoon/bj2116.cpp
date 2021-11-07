#include<iostream>
using namespace std;

int n, sideMax;
int dice[6], bottomNum[6], bottomIdx[6],
	topNum[6], topIdx[6], sumOfSide[6];
int pairIdx[6] = { 5, 3, 4, 1, 2, 0 };


void brute_force(int n);
int findSideMax(int bottom, int top);
int findIdx(int specific, int dice[]);
void initTopNum();
void initSumOfSide();
void printMax();

int main() {

	cin >> n;

	brute_force(n);
	printMax();

	return 0;
}


void brute_force(int n) {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	initTopNum();
	initSumOfSide();

	for (int i = 0; i < n; i++) {

		// 입력받기
		for (int j = 0; j < 6; j++) {
			cin >> dice[j];

			//첫 주사위 입력일 경우 임의로 초기화
			if (i == 0) { topNum[j] = dice[j]; }
		}

		for (int j = 0; j < 6; j++) {
			/* 전 주사위의 topNum은 현 주사위의 bottomNum
			현주사위의 bottomNum을 알면 topNum도 유추 가능
			(첫 주사위의 전 주사위는 없지만 위 if문에서 강제 초기화) */

			bottomNum[j] = topNum[j];	
			bottomIdx[j] = findIdx(topNum[j], dice);
			topIdx[j] = pairIdx[bottomIdx[j]]; 
			topNum[j] = dice[topIdx[j]]; 

			// bottom과 top값을 통해 나머지 네 면 중의 최대값구해서 더하기
			sideMax = findSideMax(bottomNum[j], topNum[j]);
			sumOfSide[j] += sideMax;
		}
	}
}

int findSideMax(int bottom, int top) {
	int rtn;

	if ((bottom == 6 && top == 5 )|| (bottom == 5 && top == 6))
		rtn = 4;
	else if (bottom == 6 || top == 6)
		rtn = 5;
	else
		rtn = 6;

	return rtn;
}

int findIdx(int specific, int dice[]) {

	for (int i = 0; i < 6; i++)
		if (specific == dice[i]) { return i; }

	return -1;
}

void printMax() {
	int max = 0;
	for (int i = 0; i < 6; i++) {
		if (sumOfSide[i] > max) {
			max = sumOfSide[i];
		}
	}

	cout << max;
}

void initTopNum() {
	for (int i = 0; i < 6; i++) {
		topNum[i] = 0;
	}
}

void initSumOfSide() {
	for (int i = 0; i < 6; i++) {
		sumOfSide[i] = 0;
	}
}



