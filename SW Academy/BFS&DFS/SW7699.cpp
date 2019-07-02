/////////////////////////////////////////
/*
    SWEA7699 수지의 수지 맞는 여행 
*/
/////////////////////////////////////////
#include <iostream>
using namespace std;

int T;
char field[22][22];
bool check[30];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int R, C;
int MAX;

void DFS(int x, int y, int cnt) {
	check[field[x][y]-'A'] = 1;
	for (int n = 0; n < 4; n++) {
		int nx = x + dx[n];
		int ny = y + dy[n];
		if (1 <= nx && nx <= R && C >= ny && ny >= 1 && !check[field[nx][ny]-'A']) {
				DFS(nx, ny, cnt + 1);
		}
	}
	check[field[x][y] - 'A'] = 0;
	if (MAX < cnt) MAX = cnt;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> R >> C;
		for (int r = 1; r <= R; r++) {
			for (int c = 1; c <= C; c++) {
				cin >> field[r][c];
			}
		}
		DFS(1, 1, 1);
		cout << '#' << t << ' ' << MAX << '\n';
		MAX = 0;
	}
	return 0;
}
