#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int N, field[17][17];
int cnt;
queue<pair<int, int>> h;
queue<pair<int, int>> t;

void BFS() {
	h.push({ 1,2 });
	t.push({ 1,1 });
	while (!h.empty()) {
		int hx = h.front().first;
		int hy = h.front().second;
		int tx = t.front().first;
		int ty = t.front().second;
		h.pop();
		t.pop();
		if (hx == N && hy == N) cnt++;
		
		if (hx == tx + 1 && hy == ty) {//현위치 아래방향
			if (hx + 1 <= N && field[hx + 1][hy] == 0) {//아래진행
				h.push({ hx + 1,hy });
				t.push({ tx + 1,ty });
			}
			if (hx + 1 <= N && hy + 1 <= N && field[hx + 1][hy + 1] == 0 && field[hx + 1][hy] == 0 && field[hx][hy + 1] == 0) {//대각 진행
				h.push({ hx + 1,hy + 1 });
				t.push({ tx + 1,ty });
			}
		}

		if (hx == tx + 1 && hy == ty + 1) {//현 대각
			if (hx + 1 <= N && hy + 1 <= N && field[hx + 1][hy + 1] == 0 && field[hx + 1][hy] == 0 && field[hx][hy + 1] == 0) {//대각진행
				h.push({ hx + 1,hy + 1 });
				t.push({ tx + 1,ty + 1 });
			}
			if (hx + 1 <= N && field[hx + 1][hy] == 0) {//아래진행
				h.push({ hx + 1,hy });
				t.push({ tx + 1,ty + 1 });
			}
			if (hy + 1 <= N && field[hx][hy + 1] == 0) {//오른진행
				h.push({ hx,hy + 1 });
				t.push({ tx + 1,ty + 1 });
			}
		}

		if (hx == tx && hy == ty + 1) {//현 오른
			if (hy + 1 <= N && field[hx][hy + 1] == 0) {//오른진행
				h.push({ hx,hy + 1 });
				t.push({ tx,ty + 1 });
			}
			if (hx + 1 <= N && hy + 1 <= N && field[hx + 1][hy + 1] == 0 && field[hx + 1][hy] == 0 && field[hx][hy + 1] == 0) {//대각진행
				h.push({ hx + 1,hy + 1 });
				t.push({ tx,ty + 1 });
			}
		}

	}
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) 
		for (int j = 1; j <= N; j++) 
			scanf("%d", &field[i][j]);
	BFS();
	printf("%d", cnt);
	return 0;
}
