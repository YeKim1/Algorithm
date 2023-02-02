#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {

	int N, K, A;
	vector<int> v;

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> A;
		v.push_back(A);
	}

	sort(v.begin(), v.end());

	int cnt = 0;

	for (int i = N - 1; i >= 0; i--) {
		
		while (K >= v[i]) {
			K -= v[i];
			cnt++;
		}

		if (K == 0) break;
	}

	cout << cnt;

}