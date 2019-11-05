/*
==========================
   BOJ2468 안전 영역
==========================
*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <utility>
#define INF 66663333
using namespace std;

int N, field[111][111], check[111][111];
int HMIN = INF, HMAX = 0; //지형높이 최대 최소
int tmp[111][111], area[111];//초기화하기 위한 배열, 안전영역 갯수 저장하는 배열
int MAX,cnt;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { -1,1,0,0 };
queue<pair<int, int> > q;

void field_copy() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			tmp[i][j] = field[i][j];
		}
	}
}

void field_recovery() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			field[i][j] = tmp[i][j];
		}
	}
	memset(check, 0, sizeof(check));
	cnt = 0;
} 

void rain(int K) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (field[i][j] - K < 0) {
				field[i][j] = 0;
			}
		}
	}
}

void BFS(int x, int y) {
	check[x][y] = 1;
	q.push({ x,y });
	while (!q.empty()) {
		int ox = q.front().first;
		int oy = q.front().second;
		q.pop();
		for (int n = 0; n < 4; n++) {
			int nx = ox + dx[n];
			int ny = oy + dy[n];
			if (0 <= nx && nx < N && N > ny && ny >= 0 && check[nx][ny] == 0 && field[nx][ny] > 0) {
				check[nx][ny] = 1;
				q.push({ nx,ny });
			}
		}
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &field[i][j]);
			HMIN = min(HMIN, field[i][j]);
			HMAX = max(HMAX, field[i][j]);
		}
	}
	field_copy();
	for (int k = HMIN; k <= HMAX; k++) {
		
		rain(k);

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (field[i][j] > 0 && check[i][j]==0) {
					BFS(i, j);
					cnt++;
				}
			}
		}
		area[k] = cnt;
		for (int n = HMIN; n <= HMAX; n++) {
			MAX = max(area[n], MAX);
		}
		field_recovery();
	}
	printf("%d\n", MAX);
	return 0;
}
