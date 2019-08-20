#include <iostream>
#include <queue>
#include <cstring>
#include <utility>
using namespace std;

int r, c;
char field[1010][1010];
bool check[1010][1010];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
pair<int, int> st;

int bfs(queue<pair<int, int> >& f, queue<pair<int, int> >& q) {

	int ans = 0;
	while (!q.empty()) {

		int fz = f.size();
		while (fz--) {
			int ofx = f.front().first;
			int ofy = f.front().second;
			f.pop();

			for (int dir = 0; dir < 4; dir++) {
				int nfx = ofx + dx[dir];
				int nfy = ofy + dy[dir];
				if (0 <= nfx && nfx < r && c > nfy && nfy >= 0) {
					if (field[nfx][nfy] == '.') {
						field[nfx][nfy] = 'F';
						f.push(make_pair(nfx, nfy));
					}
				}
			}
		}

		int sz = q.size();
		while (sz--) {
			int osx = q.front().first;
			int osy = q.front().second;
			q.pop();

			if (0 == osx || osx == r - 1 || c - 1 == osy || osy == 0)
				return ans + 1;

			for (int dir = 0; dir < 4; dir++) {
				int nsx = osx + dx[dir];
				int nsy = osy + dy[dir];

				if (0 <= nsx && nsx < r && c >nsy && nsy >= 0) {
					if (!check[nsx][nsy] && field[nsx][nsy] == '.') {
						check[nsx][nsy] = 1;
						q.push(make_pair(nsx, nsy));
					}
				}
			}
		}
		ans++;
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	queue<pair<int, int> > f;
	queue<pair<int, int> > q;


	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> field[i][j];

			if (field[i][j] == 'J') {
				field[i][j] = '.';
				st = make_pair(i, j);
			}
			if (field[i][j] == 'F')
				f.push(make_pair(i, j));
		}
	}


	q.push(st);
	int ret = bfs(f, q);
	if (ret == -1)
		cout << "IMPOSSIBLE" << "\n";

	else
		cout << ret << "\n";

	
	return 0;
}