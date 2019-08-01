#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
#include <vector>
using namespace std;

int n, m;
char field[505][505];
int check[505][505];
int dx[5] = { 0,-1,0,1,0 };
int dy[5] = { 0,0,1,0,-1 };
int cnt;

bool OOB(int x, int y) {
	if (0 <= x && x < n && m > y && y >= 0)
		return true;
	return false;
}

int dir(char dd) {
	if (dd == 'U')
		return 1;
	if (dd == 'R')
		return 2;
	if (dd == 'D')
		return 3;
	if (dd == 'L')
		return 4;
}

void bfs(int xx, int yy) {
	vector<pair<int, int > > v;
	v.push_back(make_pair(xx, yy));
	queue<pair<int, int> > q;
	q.push(make_pair(xx, yy));

	int vs;
	while (!q.empty()) {
		vs = v.size();
		int ox = q.front().first;
		int oy = q.front().second;
		char ddir = field[ox][oy];
		check[ox][oy] = 0;
		q.pop();

		int nx = ox + dx[dir(ddir)];
		int ny = oy + dy[dir(ddir)];
		if (!OOB(nx, ny)) {
			for (int i = 0; i < vs; i++) 
				check[v[i].first][v[i].second] = 1;
			v.clear();
			return;
		}

		else {
			if (check[nx][ny] == 1) {
				for (int i = 0; i < vs; i++) 
					check[v[i].first][v[i].second] = 1;
				v.clear();
				return;
			}

			else if (check[nx][ny] == -1) {
				v.push_back(make_pair(nx, ny));
				q.push(make_pair(nx, ny));
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
		
	
	memset(check, -1, sizeof(check));
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) 
			if (check[i][j] == -1) 
				bfs(i, j);
			
		
	int ans = 0;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) 
			if (check[i][j] == 1)
				ans++;
	
	cout << ans;
	return 0;
}