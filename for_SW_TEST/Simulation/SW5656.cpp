
//////////////////////////////////////////////
//		SW5656 벽돌깨기		 //
//////////////////////////////////////////////
/*
재귀를 이용하여 푼다.
N번만큼의 구슬을 떨어뜨리는 경우를
모두 찾아 최소값을 저장하는 것이 핵심.

*/


#include <iostream>
#define INF 0xFFFF
using namespace std;

int N, W, H;
int field[15][12];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int MIN = INF;

void cpy(int a[15][12], int b[15][12]) {
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			b[i][j] = a[i][j];
		}
	}
}

void bricksbreaking(int x, int y) {
	//if (field[x][y] == 0) return;
	int tmp = field[x][y];
	field[x][y] = 0;
	for (int k = 0; k < tmp; k++) {
		for (int n = 0; n < 4; n++) {
			int nx = x + dx[n] * k;
			int ny = y + dy[n] * k;
			if (W > ny && ny >= 0 && 0 <= nx && nx < H && field[nx][ny] != 0) {
				bricksbreaking(nx, ny);
			}
		}
	}
}

void brickssorting() {
	for (int j = 0; j < W; j++) {
		for (int i = H - 1; i >= 1; i--) {
			for (int k = i - 1; k >= 0; k--) {
				if (field[i][j] != 0) break;
				if (field[k][j] != 0) {
					field[i][j] = field[k][j];
					field[k][j] = 0;
					break;
				}
			}
		}
	}
}

void recur(int n) {
	int copy[15][12] = {};
	if (n == 0) {
		int cnt = 0;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (field[i][j] != 0) cnt++;
			}
		}
		if (MIN > cnt) MIN = cnt;
		return;
	}
	for (int j = 0; j < W; j++) {
		int x = 0, y = j;
		while (x < H && field[x][y] == 0) x++;
		cpy(field, copy);
		bricksbreaking(x, y);
		brickssorting();
		recur(n-1);
		cpy(copy, field);
	}
}


int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> W >> H;
		MIN = INF;

		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cin >> field[i][j];
			}
		}
		recur(N);
		cout << '#' << t << ' ' << MIN << '\n';
	}
	return 0;
}
