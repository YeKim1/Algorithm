#include <iostream>
using namespace std;

int N, r, c;
int ans{ 0 };

void func(int x, int y, int size) {

	if (y == r && x == c) {
		cout << ans;
		return;
	}
	else if (r < y + size && c < x + size && c >= x && r >= y) {
		func(x, y, size / 2);
		func(x + size/2, y , size / 2);
		func(x , y+size/2, size / 2);
		func(x + size / 2, y + size / 2, size / 2);
	}
	else {
		ans += size * size;
	}


}

int main() {

	cin >> N >> r >> c;

	func(0, 0, pow(2, N));
}