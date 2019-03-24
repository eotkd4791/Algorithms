/*
=============================
    BOJ14503 로봇청소기
=============================

+++++++++++++++++++++++++++++
방향키 코드 순서에서 난항을 겪음
빡구현했다가 큐에 푸시하고,
자리가 바뀌지 않은채로
다음 자리의 조건을 보고있어서
틀렸다.
다시 시험전에 다시 풀어보기
++++++++++++++++++++++++++++++
*/

include <iostream>
#include <queue>
#include <utility>
using namespace std;

int N, M;
int r, c, d;
int field[55][55];
int cnt; 
int cx[4] = { -1, 0, 1, 0 };
int cy[4] = { 0, 1, 0, -1 };
int bx[4] = { 1, 0, -1, 0 };
int by[4] = { 0, -1, 0, 1 };
queue<pair<int, int>> q;
queue<int> dir;

void BFS() {
	q.push({ r,c });
	field[r][c] = 2;
	dir.push(d);
	while (!q.empty()) {
		int ox = q.front().first;
		int oy = q.front().second;
		int stand = dir.front();
		int stare = dir.front();

		q.pop();
		dir.pop();
		field[ox][oy] = 2;

		for (int n = 0; n < 4; n++) {
			int nx, ny;
			if (stare == 0) {
				nx = ox + cx[stare + 3];
				ny = oy + cy[stare + 3];
				stare += 3;
			}
			else {
				nx = ox + cx[stare - 1];
				ny = oy + cy[stare - 1];
				stare -= 1;
			}

			if (0 <= nx && nx < N && M > ny && ny >= 0) {
				if (field[nx][ny] == 0) {
					field[nx][ny] = 2;
					q.push({ nx,ny });
					dir.push(stare);
					break;
				}
				else if (field[nx][ny] != 0) {
					if (n < 3) continue;

					if (n == 3) {
						int rx = ox + bx[stand];
						int ry = oy + by[stand];
						if (0 <= rx && rx < N && M > ry && ry >= 0) {
							if (field[rx][ry] == 1) return;
							else if (field[rx][ry] != 1) {
								q.push({ rx,ry });
								dir.push(stand);
								break;
							}
						}
					}
				}
			}
		}
	}
}


int main() {
	scanf("%d%d", &N, &M);
	scanf("%d%d%d", &r, &c, &d);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &field[i][j]);
		}
	}
	BFS();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (field[i][j] == 2) cnt++;
		}
	}
	printf("%d\n", cnt);
	return 0;
}
