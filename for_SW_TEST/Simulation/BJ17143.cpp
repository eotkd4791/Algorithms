#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int R, C, M;
typedef struct { int ss; int sd; int sz; } sh;
sh shark[101][101];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> R >> C >> M;

	int rr, cc, pp, dd, zz;
	for (int m = 0; m < M; m++) {
		cin >> rr >> cc >> pp >> dd >> zz;
		shark[rr][cc] = { pp,dd - 1,zz };
	}

	int sum = 0;
	for (int c = 1; c <= C; c++) {
		sh tmp[101][101] = {};

		//낚시왕 낚시
		for (int r = 1; r <= R; r++) {
			if (shark[r][c].sz != 0) {
				sum += shark[r][c].sz;
				shark[r][c].sz = 0;
				break;
			}
		}
		//상어 이동
		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				if (shark[i][j].sz != 0) {
					if (shark[i][j].sd < 2) {
						int ns = shark[i][j].ss % ((R - 1) * 2);
						int nx = i, ny = j;
						int nd = shark[i][j].sd;
						while (ns--) {
							if (nd == 0 && nx == 1)
								nd = 1;

							if (nd == 1 && nx == R)
								nd = 0;

							nx += dx[nd];
							ny += dy[nd];
						}
						if (tmp[nx][ny].sz < shark[i][j].sz) {
							tmp[nx][ny] = { shark[i][j].ss, nd, shark[i][j].sz };
						}
					}
					else {
						int ns = shark[i][j].ss % ((C - 1) * 2);
						int nx = i, ny = j;
						int nd = shark[i][j].sd;
						while (ns--) {
							if (nd == 2 && ny == C)
								nd = 3;

							if (nd == 3 && ny == 1)
								nd = 2;

							nx += dx[nd];
							ny += dy[nd];
						}
						if (tmp[nx][ny].sz < shark[i][j].sz) {
							tmp[nx][ny] = { shark[i][j].ss, nd, shark[i][j].sz };
						}
					}
					shark[i][j].sz = 0; shark[i][j].ss = 0;
				}
			}
		}
		memcpy(shark, tmp, sizeof(tmp));
	}
	cout << sum << '\n';
	return 0;
}