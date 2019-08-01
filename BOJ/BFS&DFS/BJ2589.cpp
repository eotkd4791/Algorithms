#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m;
char field[55][55];
int tr[55][55];

typedef struct{int x; int y; int dist;} node;
queue<node> q;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int bfs(int xx, int yy, int dd) {
	q.push({ xx,yy,dd });
	tr[xx][yy] = dd;

	int tmp = 0;
	while (!q.empty()) {
		int ox = q.front().x;
		int oy = q.front().y;
		int od = q.front().dist;
		q.pop();
		tmp = tr[ox][oy];

		for (int dir = 0; dir < 4; dir++) {
			int nx = ox + dx[dir];
			int ny = oy + dy[dir];
			int nd = tr[ox][oy] + 1;

			if (0 <= nx && nx < n && m > ny && ny >= 0 && tr[nx][ny] < 0 && field[nx][ny] == 'L') {
				tr[nx][ny] = nd;
				q.push({ nx,ny,nd });
			}
		}
	}
	return tmp;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> field[i][j];
		}
	}
	
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (field[i][j] == 'L') {
				memset(tr, -1, sizeof(tr));
				int ret = bfs(i, j, 0);
				ans = max(ans, ret);
			}
		}
	}
	cout << ans;
	return 0;
}