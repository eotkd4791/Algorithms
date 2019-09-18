#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int C, N;
int arr[101][101];
int dp[101][101];

int recur(int x, int y) {
	if (x == N) return arr[x][y];

	int& ret = dp[x][y];
	if (ret != 0) return ret;

	ret = arr[x][y] + max(recur(x + 1, y), recur(x + 1, y + 1));
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> C;
	while (C--) {
		memset(dp, 0, sizeof(dp));
		cin >> N;

		for (int i = 1; i <= N; i++) 
			for (int j = 1; j <= i; j++) 
				cin >> arr[i][j];
		
		cout << recur(1, 1) << '\n';
	}
	return 0;
}
