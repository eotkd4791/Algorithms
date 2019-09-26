#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int dp[101][1000001];
int travel[101][4];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> K;

	int ft, fm, bt, bm;
	for (int i = 0; i < N; i++) {
		cin >> ft >> fm >> bt >> bm;
		travel[i][0] = ft;
		travel[i][1] = fm;
		travel[i][2] = bt;
		travel[i][3] = bm;
	}

	for (int i = 0; i <= K; i++) {
		if (travel[0][0] <= i) 
			dp[0][i] = max(dp[0][i], travel[0][1]);
		
		if (travel[0][2] <= i) 
			dp[0][i] = max(dp[0][i], travel[0][3]);
		
	}

	for (int i = 1; i < N; i++) {
		for (int k = 1; k <= K; k++) {
		//dp[i-1][k-travel[도보,자전거시간]]이 0이라면 해당 도시를 거치지 않았다는 의미이므로..
			if (k >= travel[i][0] && dp[i - 1][k - travel[i][0]] > 0)
				dp[i][k] = max(dp[i][k], dp[i - 1][k - travel[i][0]] + travel[i][1]);

			if (k >= travel[i][2] && dp[i - 1][k - travel[i][2]] > 0)
				dp[i][k] = max(dp[i][k], dp[i - 1][k - travel[i][2]] + travel[i][3]);
		}
	}
	cout << dp[N - 1][K] << '\n';
	return 0;
}
