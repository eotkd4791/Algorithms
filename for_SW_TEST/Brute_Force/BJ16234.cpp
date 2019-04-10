////////////////////////////
/*
     BOJ16234 인구 이동
                          */
////////////////////////////

#include <iostream>
#include <queue>
#include <cmath>
#include <utility>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int N, L, R;
int a[55][55];
int check[55][55];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int idx = 1;
int sum,num;
vector<pair<int, int> >v;

bool OOB(int x, int y) {
	if (0 <= x && x < N && N > y && y >= 0)
		return true;
	return false;
}

void BFS(int x, int y) {
	queue<pair<int, int> > q = {};
	q.push({ x,y });
	while (!q.empty()) {
		int ox = q.front().first;
		int oy = q.front().second;
		check[ox][oy] = idx;
		q.pop();
		for (int n = 0; n < 4; n++) {
			int nx = ox + dx[n];
			int ny = oy + dy[n];
			if (OOB(nx,ny)) {
				int diff = abs(a[ox][oy] - a[nx][ny]);
				if (L <= diff && diff <= R) {
					if (check[nx][ny] > 0) continue; 
					check[nx][ny] = idx;
					q.push({ nx,ny });
				}
			}
		}
	}
}

void movingpeople() {
	int avr = sum / num;
	for (int i = 0; i < v.size(); i++) {
		int ox = v[i].first;
		int oy = v[i].second;
		a[ox][oy] = avr;
	}
}

void recur(int x, int y, int country) {
	check[x][y] = 0;
	v.push_back({ x,y });
	sum += a[x][y];
	num++;
	for (int n = 0; n < 4; n++) {
		int nx = x + dx[n];
		int ny = y + dy[n];
		if (OOB(nx, ny)) {
			if (check[nx][ny] > 0 && country == check[nx][ny]) {
				recur(nx, ny, check[nx][ny]);
			}
		}
	}
}


int main() {
	scanf("%d%d%d", &N, &L, &R);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &a[i][j]);
		}
	}

	int cnt = 0;
	memset(check, -1, sizeof(check));
	while (1) {
		idx = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (check[i][j] > 0) continue;
				idx++;
				BFS(i, j);
			}
		}
		if (idx == N * N) break;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (check[i][j] > 0) {
					sum = 0;
					num = 0;
					v.clear();
					recur(i, j, check[i][j]);
					movingpeople();
				}
			}
		}
		cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}