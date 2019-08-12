#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n;
int field[301][301];
int dx[] = { -1,-2,-2,-1,1,2,2,1 };
int dy[] = { -2,-1,1,2,-2,-1,1,2 };
int stx, sty, dtx, dty;
typedef struct { int x; int y; int dist; }node;

int bfs(queue<node>& q) {
	while (!q.empty()) {
		int ox = q.front().x;
		int oy = q.front().y;
		int od = q.front().dist;
		q.pop();

		if (ox == dtx && oy == dty)
			return od;

		for (int dir = 0; dir < 8; ++dir) {
			int nx = ox + dx[dir];
			int ny = oy + dy[dir];
			if (field[nx][ny] == -1 && 0 <= nx && nx<n && n > ny && ny >= 0) {
				field[nx][ny] = od + 1;
				q.push({ nx,ny,od + 1 });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--) {
		memset(field, -1, sizeof(field));
		queue<node> q;

		cin >> n;
		cin >> stx >> sty;
		cin >> dtx >> dty;
		field[stx][sty] = 0;
		q.push({ stx,sty,0 });

		cout << bfs(q) << '\n';
	}
	return 0;
}