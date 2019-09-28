#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int solution(int K, vector<vector<int>> travel) {
	int answer = 0;
	int dp[101][1000001] = {};
	
	for (int i = 0; i <= K; i++) {
		if (travel[0][0] <= i) 
			dp[0][i] = max(dp[0][i], travel[0][1]);

		if (travel[0][2] <= i) 
			dp[0][i] = max(dp[0][i], travel[0][3]);

	}
    	int vs = travel.size();
	for (int i = 1; i < vs; i++) {
		for (int k = 1; k <= K; k++) {
			if (k >= travel[i][0] && dp[i - 1][k - travel[i][0]] > 0)
				dp[i][k] = max(dp[i][k], dp[i - 1][k - travel[i][0]] + travel[i][1]);

			if (k >= travel[i][2] && dp[i - 1][k - travel[i][2]] > 0)
				dp[i][k] = max(dp[i][k], dp[i - 1][k - travel[i][2]] + travel[i][3]);
		}
	}
	answer = dp[vs - 1][K];
	return answer;
}
