#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int n, m;
char field[22][22];
bool check1[22][22];
bool check2[22][22];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
pair<int, int> f[2];

struct node {
	int fx;
	int fy;
	int sx;
	int sy;
	int cnt;
};
queue<node>q;

bool OOB(int xx, int yy) {
	if (1 <= xx && xx <= n && m >= yy && yy >= 1)
		return true;
	return false;
}

int bfs() {
	q.push({ f[0].first, f[0].second, f[1].first, f[1].second, 0 });
	int check[22][22][22][22] = {};
	check[f[0].first][f[0].second][f[1].first][f[1].second] = 1;

	int ret = -1;
	while (!q.empty()) {
		int ofx = q.front().fx;
		int ofy = q.front().fy;
		int osx = q.front().sx;
		int osy = q.front().sy;
		int od = q.front().cnt;
		check[ofx][ofy][osx][osy] = 1;
		q.pop();

		if (od > 10)
			break;

		for (int dir = 0; dir < 4; dir++) {
			int nfx = ofx + dx[dir];
			int nfy = ofy + dy[dir];
			int nsx = osx + dx[dir];
			int nsy = osy + dy[dir];

			if (field[nfx][nfy] != '#' && field[nsx][nsy] == '#') {
				nsx -= dx[dir];
				nsy -= dy[dir];
			}
			else if (field[nfx][nfy] == '#' && field[nsx][nsy] != '#') {
				nfx -= dx[dir];
				nfy -= dy[dir];
			}
			else if (field[nfx][nfy] == '#' && field[nsx][nsy] == '#')
				continue;
			

			if (OOB(nfx,nfy)) {//1¹ø µ¿Àü in
				if (OOB(nsx,nsy)) {//2¹ø µ¿Àü in
					if (!check[nfx][nfy][nsx][nsy]) {
						check[nfx][nfy][nsx][nsy] = 1;
						q.push({ nfx,nfy,nsx,nsy,od + 1 });
					}
				}
				else { //2 out
					ret = od + 1;
					return ret;
				}
			}

			else {//1¹ø µ¿Àü out
				if (OOB(nsx,nsy)) {//2 in
					ret = od + 1;
					return ret;
				}
				else //2 out
					continue;
			}
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	int t = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> field[i][j];
			if (field[i][j] == 'o') {
				f[t].first = i;
				f[t].second = j;
				t++;
			}
		}
	}
	
	int ret = bfs();
	if (ret > 10)
		ret = -1;
	cout << ret;
	return 0;
}
