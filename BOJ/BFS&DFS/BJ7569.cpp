/*
============================================
               BOJ7569 토마토2
============================================

++++++++++++++++++++++++++++++++++++++++++++
3차원 배열을 만들어서 해결했고, 큐 선언 시
페어를 하나 빠뜨려서 실수했다.
그리고 BFS를 돌고나서 growth에 0이 있으면
-1을 반환하라고 했는데 ground와 growth가
모두 0일 때 -1을 반환해야 하는 조건을 틀렸다.
차근차근 잘 생각해서 실수를 줄여야겠다.
++++++++++++++++++++++++++++++++++++++++++++
*/
#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int M, N, H;
int box[101][101][101]; //입력받는 배열
int growth[101][101][101];//토마토 좌표마다 날짜로 나타내는 배열
queue<pair<pair<int, int>,int >> q;
int dx[6] = { 0,0,0,0,-1,1 };
int dy[6] = { -1,1,0,0,0,0 };
int dz[6] = { 0,0,-1,1,0,0 };//왼 오 위 아 앞 뒤 순
int day;//토마토 익는 날짜, 큐에 한번에 푸쉬하는 그룹을 넘버링(BFS의 깊이)

void BFS() {
	int lev = growth[q.front().first.first][q.front().first.second][q.front().second];
	while (!q.empty()) {
		int ox = q.front().first.first;
		int oy = q.front().first.second;
		int oz = q.front().second;
		q.pop();

		if (lev < growth[ox][oy][oz]) {
			day++;
			lev++;
		}


		for (int i = 0; i < 6; i++) {
			int nx = ox + dx[i];
			int ny = oy + dy[i];
			int nz = oz + dz[i];

			if (0 <= nx && nx < N && M > ny && ny >= 0 && 0 <= nz && nz < H && box[nx][ny][nz] == 0 && growth[nx][ny][nz] == 0) {
				box[nx][ny][nz] = box[ox][oy][oz];
				growth[nx][ny][nz] = day + 1;
				q.push(make_pair(make_pair(nx, ny), nz));
			}
		}
	}
}

int main() {
	scanf("%d%d%d", &M, &N, &H);
	for (int h = 0; h < H; h++) {
		for (int n = 0; n < N; n++) {
			for (int m = 0; m < M; m++) {
				scanf("%d", &box[n][m][h]);
				if (box[n][m][h] == 1) {
					q.push(make_pair(make_pair(n, m), h));//다리만들기처럼 break할 필요가 없다.
				}
			}
		}
	}

	BFS();
	for (int h = 0; h < H; h++) {
		for (int n = 0; n < N; n++) {
			for (int m = 0; m < M; m++) {
				if (growth[n][m][h] == 0 && box[n][m][h]==0) {
					day = -1;
				}//0 즉, BFS이후에 안 익은 토마토가 있으면 -1 출력하고 프로그램 종료
			}
		}
	}
	printf("%d\n", day);
	return 0;
} 
