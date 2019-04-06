
////////////////////////////////////
/*
	    BOJ14500 테트로미노
                                  */
////////////////////////////////////

/*
ㅗ ㅏ ㅓ ㅜ를 예외로 빡구현하고,
나머지는 재귀를 이용한 DFS로 cnt가 4가
될 때, 최대값을 저장해놓고 되돌아 오는 방식으로
풀었다.
*/

#include <iostream>
#include <algorithm>
using namespace std;

int N, M, sum, MAX;
int field[505][505];
bool check[505][505];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

bool OOB(int x, int y) {
	if (N > x && x >= 0 && 0 <= y && y < M)
		return true;
	return false;
}

void DFS(int x, int y, int cnt) {
	if (cnt == 4) {
		check[x][y] = 1;
		sum += field[x][y];
		MAX = max(MAX, sum);
		return;
	}
	
	check[x][y] = 1;
	sum += field[x][y];

	for (int n = 0; n < 4; n++) {
		int nx = x + dx[n];
		int ny = y + dy[n];
		if (OOB(nx, ny) && !check[nx][ny]) {
			DFS(nx, ny, cnt + 1);
			check[nx][ny] = 0;
			sum -= field[nx][ny];
		}
	}
}

int hat(int x, int y) {// ㅏ ㅓ ㅗ ㅜ
	int tmp1 = 0, tmp2 = 0, tmp3 = 0, tmp4 = 0;
	if (OOB(x + 2, y) && OOB(x + 1, y + 1)) {
		tmp1 = field[x][y] + field[x + 1][y] + field[x + 1][y + 1] + field[x + 2][y];
	}
	if (OOB(x + 2, y) && OOB(x + 1, y - 1)) {
		tmp2 = field[x][y] + field[x + 1][y] + field[x + 1][y - 1] + field[x + 2][y];
	}
	if (OOB(x + 1, y - 1) && OOB(x + 1, y + 1)) {
		tmp3 = field[x][y] + field[x + 1][y] + field[x + 1][y - 1] + field[x + 1][y + 1];
	}
	if (OOB(x + 1, y + 1) && OOB(x, y + 2)) {
		tmp4 = field[x][y] + field[x][y + 1] + field[x + 1][y + 1] + field[x][y + 2];
	}
	int Mtmp = max(max(max(tmp1, tmp2), tmp3), tmp4);
	return Mtmp;
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &field[i][j]);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			sum = 0;
			DFS(i, j, 1);
			check[i][j] = 0;
			MAX = max(MAX, hat(i, j));
		}
	}
	printf("%d\n", MAX);
}