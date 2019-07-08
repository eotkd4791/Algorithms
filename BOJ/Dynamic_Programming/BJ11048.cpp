///////////////////////////////////
/*
       BOJ11048 이동하기
*/
///////////////////////////////////
#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int field[1001][1001];
int dp[1001][1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> field[i][j];
		}
	}
	dp[1][1] = field[1][1];
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			dp[i][j] = max(dp[i - 1][j] + field[i][j], max(dp[i - 1][j - 1] + field[i][j], dp[i][j - 1] + field[i][j]));//*
		}
	}
	cout << dp[N][M];
	return 0;
}