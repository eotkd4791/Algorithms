#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int R, C;
char field[55][55];
bool check[55][55];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
queue<pair<int, int> > w;
queue<pair<int, int> > h;
pair<int, int> s, d;

int bfs() {
	int ret = -1; int cnt = 0; h.push(s);

	while (!h.empty()) {
		int wz = w.size();
		while (wz--) {
			int owx = w.front().first;
			int owy = w.front().second;
			w.pop();
			for (int dir = 0; dir < 4; ++dir) {
				int nwx = owx + dx[dir];
				int nwy = owy + dy[dir];
				if (0 <= nwx && nwx < R && C > nwy && nwy >= 0 && field[nwx][nwy] == '.') {
					field[nwx][nwy] = '*';
					w.push(make_pair(nwx, nwy));
				}
			}
		}

		int hz = h.size();
		while (hz--) {
			int ohx = h.front().first;
			int ohy = h.front().second;
			h.pop();

			for (int dir = 0; dir < 4; ++dir) {
				int nhx = ohx + dx[dir];
				int nhy = ohy + dy[dir];
				if (0 <= nhx && nhx < R && C > nhy && nhy >= 0 && !check[nhx][nhy] && field[nhx][nhy]!='*' && field[nhx][nhy]!='X') {
					if (nhx == d.first && nhy == d.second)
						return cnt + 1;
					check[nhx][nhy] = 1;
					h.push(make_pair(nhx, nhy));
				}
			}
		}
		cnt++;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> field[i][j];
			if (field[i][j] == 'S') {
				check[i][j] = 1;
				field[i][j] == '.';
				s = make_pair(i, j);
			}
			else if (field[i][j] == 'D') 
				d = make_pair(i, j);
			
			else if (field[i][j] == '*')
				w.push(make_pair(i, j));
		}
	}
	
	int ret = bfs();
	if (ret == -1)
		cout << "KAKTUS";
	else
		cout << ret;
	return 0;
}