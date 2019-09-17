#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int N, M;
int field[1002][1002];
int dp[3][1002][1002]; // from up->0 from left->1 from right->2


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) 
		for (int j = 1; j <= M; j++) 
			cin >> field[i][j];
	
		
	dp[0][1][1] = dp[1][1][1] = field[1][1];
	dp[2][1][1] = INT_MIN;
	for (int j = 2; j <= M; j++) {
		dp[0][1][j] = dp[2][1][j] = INT_MIN;
		dp[1][1][j] += dp[1][1][j - 1] + field[1][j];
	}


	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= M; j++) 
			dp[0][i][j] = max(max(dp[0][i - 1][j], dp[1][i - 1][j]), dp[2][i - 1][j]) + field[i][j];
		
		for (int j = 1; j <= M; j++) {
			if (j == 1) 
				dp[1][i][j] = INT_MIN;
			
			else 
				dp[1][i][j] = max(dp[0][i][j - 1], dp[1][i][j - 1]) + field[i][j];
			
		}

		for (int j = M; j >= 1; j--) {
			if (j == M) 
				dp[2][i][j] = INT_MIN;
			
			else 
				dp[2][i][j] = max(dp[0][i][j + 1], dp[2][i][j + 1]) + field[i][j];
			
		}
	}
	cout << max(max(dp[0][N][M], dp[1][N][M]), dp[2][N][M]);
	return 0;
}
