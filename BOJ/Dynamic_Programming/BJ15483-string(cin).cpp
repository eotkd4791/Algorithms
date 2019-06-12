////////////////////////////////////
/*
       BOJ15483 최소 편집
*/
////////////////////////////////////
#include <iostream>
#include <cstring>
#include <algorithm>
#define INF 1005
using namespace std;

string str1;
string str2;
int dp[INF][INF];
int n, m;

int issame(int i, int j) {
	if (str1[i-1] == str2[j-1])
		return 0;
	return 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> str1;
	cin >> str2;

	n = str1.size();
	m = str2.size();

	memset(dp, -1, sizeof(dp));

	dp[0][0] = 0;
	for (int i = 1; i <= n; i++)
		dp[i][0] = i;
	for (int j = 1; j <= m; j++) 
		dp[0][j] = j;
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (dp[i][j] == -1)
				dp[i][j] = min(dp[i - 1][j - 1] + issame(i, j), min(dp[i - 1][j] + 1, dp[i][j - 1] + 1));
	
	cout << dp[n][m];
	return 0;
}
