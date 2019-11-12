#include <iostream>
#include <cstring>
using namespace std;

int N, M, S, E;
int arr[2001];
int dp[2001][2001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	for (int i = 0; i < N; i++) 
	{
		for (int j = N-1; j >= i; j--) 
		{
			if (i == j) 
				dp[i][j] = 1;
			
			else if (i+1 == j) 
			{
				if(arr[i] == arr[j])
					dp[i][j] = 1;
				else
					dp[i][j] = 0;
			}
			else 
			{
				if (dp[i + 1][j - 1] == 0)
					dp[i][j] = 0;
				else
				{
					if (arr[i] == arr[j]) 
						dp[i][j] = 1;
					else
						dp[i][j] = 0;
				}
			}
		}
	}
	
	cin >> M;
	for (int i = 0; i < M; i++) 
	{
		cin >> S >> E;
		S--; E--;
		cout << dp[S][E] << '\n';
	}
	return 0;
}