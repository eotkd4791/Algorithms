#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;

int N;
int field[101][101];
int sum[101][101];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
queue<pair<int,int> > q;

void BFS() {
	sum[0][0] = 0;
	while (!q.empty()) {
		int ox = q.front().first;
		int oy = q.front().second;
		q.pop();
		
		for (int n = 0; n < 4; n++) {
			int nx = ox + dx[n];
			int ny = oy + dy[n];
			if (0 <= nx && nx < N && N > ny && ny >= 0) {
				if (sum[nx][ny] == -1 || sum[ox][oy] + field[nx][ny] < sum[nx][ny]) {
					sum[nx][ny] = 0;
					sum[nx][ny] = sum[ox][oy] + field[nx][ny];
					q.push({ nx,ny });
				}
			}
		}
	}
}

int main() {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		memset(sum, -1, sizeof(sum));
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%1d", &field[i][j]);
			}
		}
		q.push({ 0,0 });
		BFS();
		int res = sum[N - 1][N - 1];
		printf("#%d %d\n", t, res);
	}
	return 0;
}