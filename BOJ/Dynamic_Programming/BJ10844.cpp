#include <iostream>
using namespace std;

int N;
long long dp[101][11];
const long long mod = 1000000000;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			if (i == 1) 
			{
				if (j == 0)
					continue;
				else
					dp[i][j] = 1;
			}
				
			else
			{
				if (j == 0)
					dp[i][j] = dp[i - 1][1] % mod;
				else
					dp[i][j] = (dp[i - 1][j - 1] % mod + dp[i - 1][j + 1] % mod) % mod;
			}
		}
	}
	long long sum = 0;
	for (int j = 0; j <= 9; j++)
		sum = ((sum % mod) + (dp[N][j] % mod)) % mod;
	cout << sum;
	return 0;
}