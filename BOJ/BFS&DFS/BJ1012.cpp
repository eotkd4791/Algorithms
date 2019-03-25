/*
=============================
BOJ1012 유기농 배추
=============================


/////////////////////////////
단지번호 매기기와 똑같은 문제,
N과M의 순서와 좌표 순서가
헷갈렸다.
스택을 이용한 DFS로 구현했다.
/////////////////////////////
*/
#include <iostream>
#include <stack>
#include <utility>
#include <cstring>
using namespace std;

int T;
int M, N, K;
int field[55][55];
bool check[55][55];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };


void DFS(int x, int y) {
	stack<pair<int, int>> s = {};
	check[x][y] = 1;
	s.push({ x,y });
	while (!s.empty()) {
		int ox = s.top().first;
		int oy = s.top().second;
		s.pop();
		for (int n = 0; n < 4; n++) {
			int nx = ox + dx[n];
			int ny = oy + dy[n];
			if (N > nx && nx >= 0 && 0 <= ny && ny < M && !check[nx][ny] && field[nx][ny] == 1) {
				check[nx][ny] = 1;
				s.push({ nx,ny });
			}
		}
	}
}

int main() {
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d%d%d", &M, &N, &K);
		for (int i = 0; i < K; i++) {
			int x, y;
			scanf("%d%d", &y, &x);
			field[x][y] = 1;
		}
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (field[i][j] == 1 && !check[i][j]) {
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