#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

int m, n, k;
int field[101][101];
bool check[101][101];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
vector<int> v;

int bfs(int xx, int yy) {
	queue<pair<int, int> > q;
	q.push(make_pair(xx, yy));
	check[xx][yy] = 1;
	int cnt = 1;

	while (!q.empty()) {
		int ox = q.front().first;
		int oy = q.front().second;
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = ox + dx[dir];
			int ny = oy + dy[dir];
			if (0 <= nx && nx < m && n > ny && ny >= 0) {
				if (!check[nx][ny] && field[nx][ny]==0) {
					cnt++;
					check[nx][ny] = 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	return cnt;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n >> k;

	int x1, y1, x2, y2;
	for (int i = 0; i < k; i++) {
		cin >> x1 >> y1 >> x2 >> y2;

		
		for (int j = x1; j < x2; j++) {
			for (int l = y1; l < y2; l++) {
				field[l][j]++;
			}
		}
	}
	for (int i = m-1; i >=0; i--) {
		for (int j = 0; j < n; j++) {
			if (!check[i][j] && field[i][j]==0) {
				int ret = bfs(i, j);
				v.push_back(ret);
			}
		}
	}
	cout << v.size() << '\n';
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << ' ';
	
	return 0;
}