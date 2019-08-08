#include <iostream>
#include <algorithm>
#include <cstring>
#include <utility>
#include <climits>
using namespace std;

int n;
int MAX;
int MIN = INT_MAX;
int idx;
int field[15][15];
bool check[15][15];
pair<int, int> core[15];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

void dfs(int which, int cnnt, int dist) {
	if (which == idx) {
		if (MAX < cnnt) {
			MAX = cnnt;
			MIN = dist;
		}
		else if (MAX == cnnt && dist < MIN) {
			MIN = dist;
		}
		return;
	}
	else {
		int ox = core[which].first;
		int oy = core[which].second;

		int fdir = 0;
		for (int i = 0; i < 4; i++) {
			int tmp = 0;

			for (int j = 1; j < n; j++) {
				int nx = ox + dx[i] * j;
				int ny = oy + dy[i] * j;

				if (check[nx][ny]) {
					if (j == 1) {
						fdir++;
						dfs(which + 1, cnnt, dist);
						break;
					}
					else if (j > 1) {
						fdir++;
						break;
					}
				}
				else {
					if (0 == nx || nx == n - 1 || n - 1 == ny || ny == 0) {
						dfs(which + 1, cnnt + 1, dist + j);
						tmp++;
						check[nx][ny] = 1;
						break;
					}
					tmp++;
					check[nx][ny] = 1;
				}
			}
			for (int m = 1; m <= tmp; m++) {
				int nx = ox + dx[i] * m;
				int ny = oy + dy[i] * m;
				check[nx][ny] = 0;
			}
			if (fdir == 4)
				dfs(which + 1, cnnt, dist);
		}
	}
	return;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		MIN = INT_MAX;
		MAX = 0;
		idx = 0;
		memset(check, 0, sizeof(check));

		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> field[i][j];
				if (field[i][j] == 1) {
					check[i][j] = 1;
					if (i != 0 && j != 0 && i != n - 1 && j != n - 1) {
						core[idx++] = make_pair(i, j);
					}
				}
			}
		}
		dfs(0, 0, 0);
		cout << '#' << t << ' ' << MIN << '\n';
	}
	return 0;
}