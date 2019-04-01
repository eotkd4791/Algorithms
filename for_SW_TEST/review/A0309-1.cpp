#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int N;
int field[16][16];
queue<pair<int, int>> h;
queue<pair<int, int>> t;

int busmoving() {
	int cnt = 0;
	if (field[0][1] == 0 && field[1][0] != 0) {
		h.push({ 0,1 });
		t.push({ 0,0 });
	}
	if (field[1][0] == 0 && field[0][1] != 0) {
		h.push({ 1,0 });
		t.push({ 0,0 });
	}
	if (field[1][0] == 0 && field[0][1]==0) {
		h.push({ 1,0 });
		t.push({ 0,0 });
		h.push({ 0,1 });
		t.push({ 0,0 });
	}
	while (!h.empty()) {
		int hx = h.front().first;
		int hy = h.front().second;
		int tx = t.front().first;
		int ty = t.front().second;
		h.pop();
		t.pop();
		if (hx == N - 1 && hy == N - 1) {//헤드가 목적지에 위치해 있고, 꼬리가 대각선 방향으로 있지 않을 때 cnt++
			if (tx == N - 2 && ty == N - 1) cnt++;
			if (tx == N - 1 && ty == N - 2) cnt++;
		}
		if (hx == tx && hy == ty + 1) { //지금방향 오른
			if (field[hx][hy + 1] == 0 && hy + 1 < N) {
				h.push({ hx,hy + 1 });
				t.push({ tx,ty + 1 });
				//다음방향 오른
			}
			if (field[hx + 1][hy + 1] == 0 && field[hx][hy + 1] == 0 && field[hx + 1][hy] == 0 && hx + 1 < N && hy + 1 < N) {
				h.push({ hx + 1,hy + 1 });
				t.push({ tx ,ty + 1 });
				//다음방향 대각
			}
		}
		if (hx == tx + 1 && hy == ty + 1) {//지금방향 대각
			if (field[hx][hy + 1] == 0 && hy + 1 < N) {
				h.push({ hx,hy + 1 });
				t.push({ tx+1,ty + 1 });
			}//다음방향 오른
			if (field[hx + 1][hy + 1] == 0 && field[hx][hy + 1] == 0 && field[hx + 1][hy] == 0 && hx + 1 < N && hy + 1 < N) {
				h.push({ hx + 1,hy + 1 });
				t.push({ tx + 1,ty + 1 });
			}//다음방향 대각
			if (field[hx + 1][hy] == 0 && hx + 1 < N) {
				h.push({ hx + 1,hy });
				t.push({ tx + 1,ty + 1 });
			}//다음방향 아래
		}
		if (hx == tx + 1 && hy == ty) {//지금방향 아래
			if (field[hx + 1][hy] == 0 && hx + 1 < N) {
				h.push({ hx + 1,hy });
				t.push({ tx + 1,ty });
				//다음방향 아래
			}
			if (field[hx + 1][hy + 1] == 0 && field[hx][hy + 1] == 0 && field[hx + 1][hy] == 0 && hx + 1 < N && hy + 1 < N) {
				h.push({ hx + 1,hy + 1 });
				t.push({ tx + 1,ty });
				//다음방향 대각
			}
		}
	}
	return cnt;
}

int main() {
	int T=0;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &field[i][j]);
			}
		}
		printf("#%d %d\n", t, busmoving());
	}
	return 0;
}
