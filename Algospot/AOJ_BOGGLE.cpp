#include <iostream>
#include <cstring>
using namespace std;

int c, n;
char que[5][5];
int dx[8] = { 0,0,1,-1,1,1,-1,-1 };
int dy[8] = { 1,-1,0,0,1,-1,1,-1 };
int dp[5][5][11];
bool esc;

void DFS(int x, int y, string *st, int idx,int ch) {//문자열, 몇번째 문자열, 몇번째 문자
	dp[x][y][ch] = 1;
	if (ch == st[idx].size()) {
		esc = 1;
		return;
	}
	for (int d = 0; d < 8; d++) {
		int nx = x + dx[d];
		int ny = y + dy[d];
		if (0 <= nx && nx < 5 && 5 > ny && ny >= 0 ) {
			if (que[nx][ny] == st[idx][ch] && dp[nx][ny][ch+1] == 0) {
				DFS(nx, ny, st, idx, ch + 1);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> c;
	for (int cc = 1; cc <= c; cc++) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				cin >> que[i][j];
			}
		}

		cin >> n;
		string st[10];
		for (int i = 0; i < n; i++) 
			cin >> st[i];
		
		for (int i = 0; i < n; i++) {
			memset(dp, 0, sizeof(dp));
			for (int a = 0; a < 5; a++) {
				for (int b = 0; b < 5; b++) {
					if (st[i][0] == que[a][b]) {
						DFS(a, b, st, i, 1);
						if (esc) break;
					}
				}
				if (esc) break;
			}
			if (esc) {
				esc = 0;
				cout << st[i] << ' ' << "YES" << '\n';
			}
			else {
				cout << st[i] << ' ' << "NO" << '\n';
			}
		}
	}
	return 0;
}
