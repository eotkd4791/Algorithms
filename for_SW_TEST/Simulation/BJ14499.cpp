/*
============================
    BOJ14499 주사위굴리기
============================


*/

#include <iostream>
using namespace std;
int N, M, x, y, l;
int arr[20][20];
int dice[7];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

int main() {
	scanf("%d%d%d%d%d", &N, &M, &x, &y, &l);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	while (l--) {
		int K;
		scanf("%d", &K);

		int nx = x + dx[K - 1];
		int ny = y + dy[K - 1];
		if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

		if (K == 1) {
			int tmp = dice[1];
			dice[1] = dice[3];
			dice[3] = dice[6];
			dice[6] = dice[4];
			dice[4] = tmp;
		}
		else if (K == 2) {
			int tmp = dice[1];
			dice[1] = dice[4];
			dice[4] = dice[6];
			dice[6] = dice[3];
			dice[3] = tmp;
		}
		else if (K == 3) {
			int tmp = dice[1];
			dice[1] = dice[5];
			dice[5] = dice[6];
			dice[6] = dice[2];
			dice[2] = tmp;
		}
		else {
			int tmp = dice[1];
			dice[1] = dice[2];
			dice[2] = dice[6];
			dice[6] = dice[5];
			dice[5] = tmp;
		}
		x = nx;
		y = ny;
		if (arr[x][y] == 0) arr[x][y] = dice[6];
		else {
			dice[6] = arr[x][y];
			arr[x][y] = 0;
		}
		printf("%d\n", dice[1]);
	}
	return 0;
}
