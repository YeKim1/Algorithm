#include <iostream>
using namespace std;

int tree[65][65];
string ans = "";

int check(int x, int y, int size) {
	int color = tree[x][y];
	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++) {
			if (tree[j][i] != color) return -1;
		}
	}
	return color;
}

void func(int x, int y, int size) {
	if (check(x, y, size) != -1) ans += check(x, y, size);
	else {
		ans += "(";
		func(x, y, size / 2);
		func(x + size / 2, y, size / 2);
		func(x, y + size / 2, size / 2);
		func(x + size / 2, y + size / 2, size / 2);
		ans += ")";
	}
}

int main() {
	int n;
	cin >> n;

	string tmp;
	for (int y = 1; y <= n; y++) {
		cin >> tmp;
		for (int x = 1; x <= n; x++) {
			tree[x][y] = tmp[x - 1];
		}
	}

	func(1, 1, n);
	cout << ans;
}