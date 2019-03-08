#include <iostream>
#include <queue>
#include <utility>
#define INF 66663333
using namespace std;

int N, M;
int field[110][110];
int arr[110][110];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int MIN=INF;

void BFS(int x, int y,int z) {
	queue<pair<int, int> > q;
	queue<int> c;
	arr[1][1] = 1;
	q.push(make_pair(x, y));
	c.push(z);
	while (!q.empty() || !c.empty()) {
		int xnow = q.front().first;
		int ynow = q.front().second;
		int cnt = c.front();
		q.pop();
		c.pop();
		for (int n = 0; n < 4; n++) {
			int nx = xnow + dx[n];
			int ny = ynow + dy[n];
			if (nx > 0 && ny > 0 && nx <= N && ny <= M && field[nx][ny] == 1 && arr[nx][ny]==0) {
				q.push(make_pair(nx, ny));
				c.push(cnt + 1);
				arr[nx][ny] = cnt + 1;
			}
		}
	}
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%1d", &field[i][j]);
		}
	}
	BFS(1,1,1);
	int ans=arr[N][M];
	MIN = min(ans, MIN);
	printf("%d\n", MIN);
	return 0;
}