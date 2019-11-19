#include <iostream>
using namespace std;

int N;
int dp[101][11];
const int mod = 1000000000;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;

	for (int j = 1; j <= 9; j++)
		dp[1][j] = 1;
	for (int i = 2; i <= N; i++) 
		for (int j = 0; j <= 9; j++)
		{
			if (j == 0)
				dp[i][j] = dp[i - 1][1];
			else
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % mod;
		}

	int sum = 0;
	for (int j = 0; j <= 9; j++)
		sum = (sum + dp[N][j] % mod) % mod;
	cout << sum << '\n';
	return 0;
}