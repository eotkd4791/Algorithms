#include <iostream>
#include <utility>
#include <queue>
#include <cstring>
using namespace std;

int n, m;
int field[301][301];
int melt[301][301];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
bool check[301][301];
queue<pair<int, int> > q;

void BFS(int xx, int yy) {
	q.push(make_pair(xx, yy));
	check[xx][yy] = 1;

	while (!q.empty()) {
		int ox = q.front().first;
		int oy = q.front().second;
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = ox + dx[dir];
			int ny = oy + dy[dir];
			if (0 <= nx && nx < n && m > ny && ny >= 0) {
				if (!check[nx][ny]) {
					if (field[nx][ny] <= 0)
						melt[ox][oy]++;
					else {
						check[nx][ny] = 1;
						q.push(make_pair(nx, ny));
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
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> field[i][j];

	int cnt = 0;
	while (1) {
		int land = 0;
		memset(check, 0, sizeof(check));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (field[i][j] > 0 && !check[i][j]) {
					BFS(i, j);
					land++;
				}
			}
		}
		if (land == 0) {
			cnt = 0;
			break;
		}
		if (land > 1) 
			break;
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				field[i][j] -= melt[i][j];
				melt[i][j] = 0;
			}
		}
		cnt++;
	}
	cout << cnt;
	return 0;
}
