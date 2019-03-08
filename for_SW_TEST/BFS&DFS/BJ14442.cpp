#include <iostream>
#include <algorithm>
#include <queue>
#define INF 66663333
using namespace std;

int N, M, K;
int field[1111][1111];
int mark[1111][1111][11];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int MIN = INF;

void BFS(int x, int y, int z) {
	queue<pair<int, int>>q;
	queue<int> c;
	mark[0][0][0] = 1;
	q.push({ x,y });
	c.push(z);
	while (!q.empty() || !c.empty()) {
		int ox = q.front().first;
		int oy = q.front().second;
		int cntbrk = c.front();
		q.pop();
		c.pop();
		for (int n = 0; n < 4; n++) {
			int nx = ox + dx[n];
			int ny = oy + dy[n];
			if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
				if (field[nx][ny] == 0 && mark[nx][ny][cntbrk] == 0) {
					mark[nx][ny][cntbrk] = mark[ox][oy][cntbrk] + 1;
					q.push({ nx,ny });
					c.push(cntbrk);
				}
				if (cntbrk + 1 <= K && field[nx][ny] == 1 && mark[nx][ny][cntbrk + 1] == 0) {
					mark[nx][ny][cntbrk + 1] = mark[ox][oy][cntbrk] + 1;
					q.push({ nx,ny });
					c.push(cntbrk + 1);
				}
			}
		}
	}
}

int main() {
	scanf("%d%d%d", &N, &M, &K);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &field[i][j]);
		}
	}
	BFS(0, 0, 0);

	int ans = -1;
	for (int i = 0; i <= K; i++) {
		if (mark[N - 1][M - 1][i] == 0) continue;
		if (ans == -1) {
			ans = mark[N - 1][M - 1][i];
		}
		else if (ans > mark[N - 1][M - 1][i]) {
			ans = mark[N - 1][M - 1][i];
		}
	}
	printf("%d\n", ans);
	return 0;
}