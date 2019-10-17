#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <climits>
using namespace std;

int MIN = INT_MAX;
int field[4][5][5][5];
int maze[5][5][5];
int dist[5][5][5];
bool check[5][5][5];
int dx[] = { 0,0,0,0,1,-1 };
int dy[] = { 0,0,1,-1,0,0 };
int dz[] = { 1,-1,0,0,0,0 };
struct node { int x; int y; int z; };

inline bool OOB(int xx, int yy, int zz) {
	if (0 <= xx && xx < 5 && 5 > yy && yy >= 0 && 0 <= zz && zz < 5)
		return true;
	return false;
}

int bfs() {
	if (maze[0][0][0] == 0 || maze[4][4][4] == 0)
		return INT_MAX;

	queue<node> q;
	memset(dist,-1,sizeof(dist));

	q.push({ 0,0,0 });
	dist[0][0][0] = 0;

	while (!q.empty()) {
		node cur = q.front();
		q.pop();

		for (int dir = 0; dir < 6; dir++) {
			int nx = cur.x + dx[dir];
			int ny = cur.y + dy[dir];
			int nz = cur.z + dz[dir];

			if (OOB(nx, ny, nz) && dist[nx][ny][nz]==-1 && maze[nx][ny][nz] == 1) {
				dist[nx][ny][nz] = dist[cur.x][cur.y][cur.z] + 1;
				node next = { nx,ny,nz };
				if (nx == 4 && ny == 4 && nz == 4)
					return dist[cur.x][cur.y][cur.z] + 1;
				q.push(next);
			}
		}
	}
	return INT_MAX;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);


	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++)
			for (int k = 0; k < 5; k++)
				cin >> field[0][i][j][k];


		for (int l = 1; l < 4; l++)
			for (int j = 0; j < 5; j++)
				for (int k = 0; k < 5; k++)
					field[l][i][j][k] = field[l - 1][i][4 - k][j];

	}


	int stackin[5] = { 0,1,2,3,4 };
	do {
		for (int dd = 0; dd < 1024; dd++) {
			int tmp = dd;
			for (int i = 0; i < 5; i++) {
				int turn = tmp % 4;
				tmp /= 4;

				for (int j = 0; j < 5; j++)
					for (int k = 0; k < 5; k++)
						maze[i][j][k] = field[turn][stackin[i]][j][k];

			}
			MIN = min(MIN, bfs());
		}
	} while (next_permutation(stackin, stackin + 5));
	if (MIN == INT_MAX)
		MIN = -1;
	cout << MIN;
	return 0;
}