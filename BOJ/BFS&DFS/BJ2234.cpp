#include <iostream>
#include <algorithm>
#include <cstring>
#include <utility>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

int n, m;
int check[55][55];
int field[55][55];
int area[55][55];
int dx[] = { 0,-1,0,1 };
int dy[] = { -1,0,1,0 };
int croom;
int mroom;
int proom;
int cnt;
queue<pair<int, int> > q;
vector<int> w;
vector<vector<int> > v;

void rBFS(int x, int y) {
	q.push({ x,y });
	while (!q.empty()) {
		int ox = q.front().first;
		int oy = q.front().second;
		area[ox][oy] = croom + 1;
		cnt++;
		q.pop();
		
		int dir = field[ox][oy];
		for (int d = 0; d < 4; d++) {
			if (dir % 2 == 0) {
				int nx = ox + dx[d];
				int ny = oy + dy[d];
				if (check[nx][ny] == 0) {
					check[nx][ny] = 1;
					q.push(make_pair(nx, ny));
				}
			}
			dir /= 2;
		}
	}
}

void pBFS(int x, int y) {
	q.push({ x,y });
	bool arr[2501] = {};
	while (!q.empty()) {
		int ox = q.front().first;
		int oy = q.front().second;
		arr[area[ox][oy]] = 1;
		q.pop();
		for (int d = 0; d < 4; d++) {
			int nx = ox + dx[d];
			int ny = oy + dy[d];
			if (1 <= nx && nx <= m && n >= ny && ny >= 1) {
				if (check[nx][ny] == 0) {
					check[nx][ny] = 1;
					if (area[ox][oy] == area[nx][ny])
						q.push({ nx, ny });
					else if (!arr[area[nx][ny]]) {
						arr[area[nx][ny]] = 1;
						v[area[ox][oy]].push_back(area[nx][ny]);
					}
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			cin >> field[i][j];

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (check[i][j] == 0) {
				check[i][j] = 1;
				rBFS(i, j);
				mroom = max(mroom, cnt);
				w.push_back(cnt);
				cnt = 0;
				croom++;
			}
		}
	}

	v.resize(croom + 1);
	memset(check, 0, sizeof(check));
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (check[i][j] == 0) {
				check[i][j] = 1;
				pBFS(i, j);
			}
		}
	}

	for (int i = 1; i <= croom; i++) {
		int sz = v[i].size();
		for (int j = 0; j < sz; j++) {
			int sum = w[i - 1] + w[v[i][j] - 1];
			proom = max(proom, sum);
		}
	}

	if (n == 1 || m == 1) proom = mroom + 1;
	cout << croom << '\n';
	cout << mroom << '\n';
	cout << proom << '\n';
	return 0;
}
