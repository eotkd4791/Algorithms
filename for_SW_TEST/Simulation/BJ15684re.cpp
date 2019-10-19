#include <iostream>
using namespace std;

int N, M, H;
int field[35][15]; //1 <= y <= N //  1 <= x <= H;
int MIN = 4;

bool go() {
	for (int j = 1; j <= N; j++) {
		int sty = j;
		for (int h = 1; h <= H; h++) {
			if (field[h][sty] == 1) {
				sty++;
			}
			else if (field[h][sty - 1] == 1) {
				sty--;
			}
		}
		if (sty != j)
			return false;
	}
	return true;
}

void cmb(int h, int n, int cnt) {
	if (cnt >= MIN)
		return;
	if (go()) {
		MIN = cnt;
		return;
	}
	if (cnt == 3) return;
	for (int i = h; i <= H; i++) {
		for (int j = 1; j <= N; j++) {
			if (field[i][j] == 1 || field[i][j + 1] == 1 || field[i][j-1]==1)
				continue;
			field[i][j] = 1;
			cmb(i, j, cnt + 1);
			field[i][j] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int a, b;
	cin >> N >> M >> H;
	for (int m = 0; m < M; m++) {
		cin >> a >> b;
		field[a][b] = 1;
	}
	cmb(1, 1, 0);
	if (MIN >= 4)
		MIN = -1;
	cout << MIN;
	return 0;
}