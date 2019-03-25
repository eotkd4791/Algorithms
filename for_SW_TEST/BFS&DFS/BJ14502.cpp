/*
==========================================
       BOJ14502 연구소
==========================================
//////////////////////////////////////////
//DFS를 이용한 백트래킹으로 벽을 세우고   
//바이러스를 퍼트리고 안전지대 영역 갯수를
//MAX에 저장 후, 미리 복사해놓은 배열로  
//다시 초기화 시켰다.                   
//////////////////////////////////////////

*/

#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>
#include <cstring>
using namespace std;

int N, M;
int field[10][10],tmp[10][10],rec[10][10];
int MAX;
bool check[10][10];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
queue<pair<int, int>> q;


void mapcpy() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			rec[i][j]=tmp[i][j];
		}
	}
}

void virus() {
	mapcpy();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (tmp[i][j] == 2) q.push({ i,j });
		}
	}

	while (!q.empty()) {
		int ox = q.front().first;
		int oy = q.front().second;
		tmp[ox][oy] = 2;
		q.pop();
		for (int n = 0; n < 4; n++) {
			int nx = ox + dx[n];
			int ny = oy + dy[n];
			if (tmp[nx][ny] == 0 && nx >= 0 && 0 <= ny && ny<M && N>nx) {
				q.push({ nx,ny });
			}
		}
	}
	int safe = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (tmp[i][j] == 0) safe++;
		}
	}
	MAX = max(MAX, safe);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			tmp[i][j] = rec[i][j];
		}
	}
	return;
}

void dfs_wall(int cnt) {
	if (cnt == 3) {
		virus();
		return;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!check[i][j] && tmp[i][j] == 0) {
				tmp[i][j] = 1;
				check[i][j] = 1;
				dfs_wall(cnt + 1);
				check[i][j]=0;
				tmp[i][j] = 0;
			}
		}
	}
}


int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &field[i][j]);
			tmp[i][j] = field[i][j];
		}
	}
	
	dfs_wall(0);
	printf("%d\n", MAX);
	return 0;
}