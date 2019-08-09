#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
#include <cstring>
using namespace std;

int w, h;
char field[101][101];
int check[101][101];
typedef struct { int X; int Y; int cnt; }mir;
queue<mir> q;
pair<int, int> st;
pair<int, int> en;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

void bfs() {
	while (!q.empty()) {
		int ox = q.front().X;
		int oy = q.front().Y;
		int oc = q.front().cnt;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = ox + dx[i];
			int ny = oy + dy[i];
			while (0 <= nx && nx < h && w > ny && ny >= 0) {
				if (field[nx][ny] == '*')
					break;
				else {
					if (check[nx][ny] == -1) {
						check[nx][ny] = oc;
						q.push({ nx,ny,oc + 1 });
					}
				}
				nx += dx[i];
				ny += dy[i];
			}
		}
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	memset(check, -1, sizeof(check));

	cin >> w >> h;
	bool flag = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> field[i][j];
			if (!flag && field[i][j] == 'C') {
				flag = 1;
				st = make_pair(i, j);
				check[i][j] = 0;	
				q.push({ i,j,0 });
			}
			if (flag && field[i][j] == 'C') 
				en = make_pair(i, j);
		}
	}
	bfs();
	cout << check[en.first][en.second] << '\n';
	return 0;
}