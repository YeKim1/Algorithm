#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int stair[301] = { 0 };
int DP[301] = { 0 };

int main() {

	int N;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> stair[i];
	}

	vector<int> DP(N + 1);

	DP[0] = stair[0];
	DP[1] = stair[0] + stair[1];
	DP[2] = max(stair[0] + stair[2], stair[1] + stair[2]);

	// 연속된 세 개의 계단을 모두 밟아서는 안 된다. <- 해결해야 함
	
	for (int i = 3; i < N; i++) {
		DP[i] = max(stair[i] + DP[i - 2], stair[i] + stair[i - 1] + DP[i - 3]);
	}

	cout << DP[N - 1];
	

}