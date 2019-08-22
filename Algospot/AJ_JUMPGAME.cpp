#include <iostream>
#include <cstring>
using namespace std;

int N;
int field[101][101];
int dp[101][101];
int dx[] = { 0,1 };
int dy[] = { 1,0 };

int recur(int x, int y, int z) {
	dp[x][y] = 1;
	if (x == N - 1 && y == N - 1) 
		return 1;
	
	else {
		for (int dir = 0; dir < 2; ++dir) {
			int nx = x + dx[dir] * z;
			int ny = y + dy[dir] * z;
			if (nx < N && N > ny) {
				if(dp[nx][ny] != 1)
					dp[nx][ny] = recur(nx, ny, field[nx][ny]);
			}
			else {
				if (dir == 0) 
					continue;
				else 
					dp[x][y] = 0;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int C;
	cin >> C;
	while (C--) {
		memset(dp, -1, sizeof(dp));
		cin >> N;
		for (int i = 0; i < N; i++) 
			for (int j = 0; j < N; j++) 
				cin >> field[i][j];
			
		int ret = recur(0, 0, field[0][0]);
		if (dp[N-1][N-1] == 1)
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";
	}
	return 0;
}