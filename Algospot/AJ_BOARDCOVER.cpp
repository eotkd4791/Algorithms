#include <iostream>
#include <utility>
using namespace std;

int H, W;
int b, ans, ret;
char field[22][22];
bool check[22][22];
pair<int, int> dir[4][3] = { {{0,0},{1,0},{0,1}}, {{0,0},{1,1},{0,1}}, {{0,0},{1,0},{1,1}}, {{0,0},{1,0},{1,-1}} };

bool pos(int nn, int xx, int yy) {
	for (int k = 0; k < 3; k++) {
		int nx = xx + dir[nn][k].first;
		int ny = yy + dir[nn][k].second;
		if (1 > nx || nx > H || 1 > ny || ny > W || check[nx][ny] || field[nx][ny] != '.')
			return false;
	}
	return true;
}

int dfs() {
	int stx = -1, sty = -1;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			if (field[i][j] == '.' && !check[i][j]) {
				stx = i; sty = j;
				break;
			}
		}
		if (stx != -1 || sty != -1) break;
	}
	if (stx == -1 && sty == -1) return 1;

	int ret = 0;
	for (int n = 0; n < 4; n++) {
		if (pos(n, stx, sty)) {
			for (int k = 0; k < 3; k++) {
				int nx = stx + dir[n][k].first;
				int ny = sty + dir[n][k].second;
				check[nx][ny] = 1;
			}
			ret += dfs();
			for (int k = 0; k < 3; k++) {
				int nx = stx + dir[n][k].first;
				int ny = sty + dir[n][k].second;
				check[nx][ny] = 0;
			}
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int C;
	cin >> C;
	while (C--) {
		cin >> H >> W;
		for (int i = 1; i <= H; i++) {
			for (int j = 1; j <= W; j++) {
				cin >> field[i][j];
			}
		}
		int ans = dfs();
		cout << ans << '\n';
	}
	return 0;
}