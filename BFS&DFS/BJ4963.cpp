/*배열초기화를 빼먹어서 푸는 시간이 지연됬다. 기본적인 실수 줄이기..
너비와 높이를 바꿔썼기 때문에 답이 안나왔다. 기본적인 부분 신경쓰기.*/
#include <iostream>
#include <utility>
#include <cstring>
using namespace std;
int field[55][55], check[55][55];
int dx[8] = { 1,-1,0,0,1,-1,-1,1 };
int dy[8] = { 0,0,1,-1,1,1,-1,-1 };
int w, h;

void DFS(int x, int y) {
	check[x][y] = 1;
	for (int n = 0; n < 8; n++) {
		int rx = x + dx[n];
		int ry = y + dy[n];
		if (rx >= 0 && ry >= 0 && rx < h && ry < w && check[rx][ry] == 0 && field[rx][ry] == 1) {
			check[rx][ry] = 1;
			DFS(rx, ry);
		}
	}
}

int main() {
	while (1) {
		scanf("%d%d", &w, &h);
		if (w == 0 && h == 0) break; 
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				scanf("%d", &field[i][j]);
			}
		}
		int cnt = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (field[i][j] == 1 && check[i][j]==0) {
					DFS(i, j);
					cnt++;
				}
			}
		}
		printf("%d\n", cnt);
		memset(field, 0, sizeof(field));
		memset(check, 0, sizeof(check));
	}
	return 0;
}
