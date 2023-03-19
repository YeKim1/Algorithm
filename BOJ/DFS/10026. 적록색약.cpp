#include <iostream>
using namespace std;

char arr[101][101];
bool visit[101][101] = { false };
int n;

int X[4] = {1, -1, 0 ,0};
int Y[4] = {0, 0, 1, -1};

void dfs(int x, int y) {

	visit[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int move_x{ x + X[i] }, move_y{ y + Y[i] };
		if (move_x >= 1 && move_x <= n && move_y >= 1 && move_y <= n) {
			if (arr[x][y] == arr[move_x][move_y] && !visit[move_x][move_y]) dfs(move_x, move_y);
		}
	}
}

void dfs_false(int x, int y) {

}

int main() {

	cin >> n;

	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= n; x++) {
			cin >> arr[x][y];
		}
	}

	int cnt1{ 0 }, cnt2{ 0 };

	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= n; x++) {
			if (!visit[x][y]) {
				dfs(x, y);
				cnt1++;
			}
		}
	}

	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= n; x++) {
			if (arr[x][y] == 'R') arr[x][y] = 'G';
		}
	}

	memset(visit, false, sizeof(visit));

	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= n; x++) {
			if (!visit[x][y]) {
				dfs(x, y);
				cnt2++;
			}
		}
	}

	cout << cnt1 << " " << cnt2;
}