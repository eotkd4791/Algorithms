/*BOJ미로탐색-2178
BOJ벽 부수고 이동하기2-14442와 비슷한 문제유형이다. 
푸는 방법 숙지하기*/

#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int N, M;
int field[110][110];
int arr[110][110];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };


void BFS(int x, int y) {
	queue<pair<int, int> > q;
	queue<int> c;
	int cnt = 1;
	arr[1][1] = 1;
	q.push(make_pair(x, y));
	c.push(cnt);
	while (!q.empty() || !c.empty()) {
		int xnow = q.front().first;
		int ynow = q.front().second;
		cnt = c.front();
		q.pop();
		c.pop();
		if (xnow == N && ynow == M) return;
		for (int n = 0; n < 4; n++) {
			int nx = xnow + dx[n];
			int ny = ynow + dy[n];
			if (nx > 0 && ny > 0 && nx <= N && ny <= M && field[nx][ny] == 1 && arr[nx][ny] == 0) {
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
	BFS(1, 1);
	int ans = arr[N][M];
	printf("%d\n", ans);
	return 0;
}
