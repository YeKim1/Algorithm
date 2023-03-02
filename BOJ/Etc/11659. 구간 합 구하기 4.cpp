#include <iostream>
using namespace std;

int main() {
	int n, m, i, j;

	cin >> n >> m;

	int* arr = new int[n + 1];
	int* sum = new int[n + 1];
	sum[0] = 0;

	for (int cnt = 1; cnt <= n; cnt++) {
		cin >> arr[cnt];
		sum[cnt] = sum[cnt - 1] + arr[cnt];
		cout << sum[cnt] << "\n";
	}

	for (int cnt = 0; cnt < m; cnt++) {
		cin >> i >> j;
		cout << sum[j] - sum[i - 1] << "\n";
		cout << sum[j] << " " << sum[i] << "\n";
	}
}

