#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>
#include <climits>
using namespace std;

int n, m;
int field[1001][1001];
int tmp[1001][1001][2];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int MIN = INT_MAX;
struct node {
	int x;
	int y;
	int b;
};
queue<node> q;

int bfs() {
	int ret = -1;
	while (!q.empty()) {
		int ox = q.front().x;
		int oy = q.front().y;
		int ob = q.front().b;
		q.pop();
		
		for (int dir = 0; dir < 4; dir++) {
			int nx = ox + dx[dir];
			int ny = oy + dy[dir];
			
			if (1 <= nx && nx <= n && m >= ny && ny >= 1) {
				if (ob==1 && field[nx][ny]==1 && tmp[nx][ny][ob]==0) {
					tmp[nx][ny][ob-1] = tmp[ox][oy][ob] + 1;
					q.push({ nx,ny,ob-1 });
				}
				if (field[nx][ny]==0 && tmp[nx][ny][ob] == 0) {
					tmp[nx][ny][ob] = tmp[ox][oy][ob] + 1;
					q.push({ nx,ny,ob });
				}
			}
		}
	}
	for (int k = 0; k < 2; k++) 
		if (tmp[n][m][k]!=0) 
			MIN = min(MIN, tmp[n][m][k]);
	ret = MIN;
	return ret;
}


int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j ++) {
			scanf("%1d", &field[i][j]);
		}
	}
	
	q.push({1,1,1});
	tmp[1][1][1] = 1;

	int ret = bfs();
	if (ret == INT_MAX)
		ret = -1;

	printf("%d\n", ret);
	return 0;
}