#include <iostream>
using namespace std;

int N, M, H;
int field[35][15];
int ans = 4;

bool check() {
	for (int n = 1; n <= N; n++) {
		int tmp = n;
		for (int h = 0; h <= H; h++) {
			if (field[h][tmp] == 1)
				tmp++;
			else if (field[h][tmp - 1] == 1)
				tmp--;
		}
		if (n != tmp)
			return false;
	}
	return true;
}

void recur(int h, int n, int cnt) {
	if (cnt >= ans) return;
	if (check()) {
		ans = cnt;
		return;
	}
	if (cnt == 3) return;
	for (int i = h; i <= H; i++) {
		for (int j =  1; j <= N; j++) {
			if (field[i][j] == 0 && field[i][j - 1] == 0 && field[i][j + 1] == 0) {
				field[i][j] = 1;
				recur(i, j, cnt + 1);
				field[i][j] = 0;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> H;
	if (M == 0) {
		cout << "0" << '\n';
		return 0;
	}
	else {
		int a, b;
		for (int m = 0; m < M; m++) {
			cin >> a >> b;
			field[a][b] = 1;
		}
		recur(1, 1, 0);
		if (ans == 4) ans = -1;
		cout << ans;
	}
	return 0;
}