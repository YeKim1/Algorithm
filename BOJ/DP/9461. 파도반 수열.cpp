#include <iostream>
using namespace std;

long long DP[1001];

int main() {
	int T, N;

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> N;

		DP[1] = 1;
		DP[2] = 1;
		DP[3] = 1;
		DP[4] = 2;
		DP[5] = 2;
		
		for (int i = 6; i <= N; i++) {
			DP[i] = DP[i - 1] + DP[i - 5];
		}

		cout << DP[N] << "\n";
		
	}
}