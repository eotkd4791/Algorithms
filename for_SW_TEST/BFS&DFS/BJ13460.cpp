#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int n, m;
char field[11][11];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

struct node {
	int rx, ry, bx, by, d;
};
node st;
queue<node> q;

int bfs() {
	int visit[10][10][10][10] = { 0, };

	int ret = -1;
	while (!q.empty()) {
		node cur = q.front();
		visit[cur.rx][cur.ry][cur.bx][cur.by] = 1;
		q.pop();
		if (cur.d > 10)
			break;
		if (field[cur.rx][cur.ry] == 'O' && field[cur.bx][cur.by] != 'O') {
			ret = cur.d;
			break;
		}
		for (int dir = 0; dir < 4; dir++) {

			int next_rx = cur.rx;
			int next_ry = cur.ry;
			int next_bx = cur.bx;
			int next_by = cur.by;

			while (1) {
				if (field[next_rx][next_ry] != '#' && field[next_rx][next_ry] != 'O') {
					next_rx += dx[dir];
					next_ry += dy[dir];
				}
				else {
					if (field[next_rx][next_ry] == '#') {
						next_rx -= dx[dir];
						next_ry -= dy[dir];
					}
					break;
				}
			}
			while (1) {
				if (field[next_bx][next_by] != '#' && field[next_bx][next_by] != 'O') {
					next_bx += dx[dir];
					next_by += dy[dir];
				}

				else {
					if (field[next_bx][next_by] == '#') {
						next_bx -= dx[dir];
						next_by -= dy[dir];
					}
					break;
				}
			}
			if (next_rx == next_bx && next_ry == next_by) {
				if (field[next_rx][next_ry] != 'O') {
					int rd = abs(next_rx - cur.rx) + abs(next_ry - cur.ry);
					int bd = abs(next_bx - cur.bx) + abs(next_by - cur.by);
					if (rd < bd) {
						next_bx -= dx[dir];
						next_by -= dy[dir];
					}
					else {
						next_rx -= dx[dir];
						next_ry -= dy[dir];
					}
				}
			}
			if (visit[next_rx][next_ry][next_bx][next_by] == 0) {
				visit[next_rx][next_ry][next_bx][next_by] = 1;
				node next;
				next.rx = next_rx;
				next.ry = next_ry;
				next.bx = next_bx;
				next.by = next_by;
				next.d = cur.d + 1;
				q.push(next);
			}
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> field[i][j];
			if (field[i][j] == 'R') {
				st.rx = i;
				st.ry = j;
			}
			if (field[i][j] == 'B') {
				st.bx = i;
				st.by = j;
			}
		}
	}
	q.push({ st.rx, st.ry, st.bx, st.by, 0 });
	int ret = bfs();
	cout << ret;
	return 0;
} 
