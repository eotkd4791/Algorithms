//11057 오르막수
//점화식을 찾는 과정이 어려웠다.
//dp[i][j]에서 i는 자릿수 ,j는 끝자리
//예를 들어, dp[3][8]에서 _ _ 8까지의 오르막수의 갯수 = _ 8 8 + _ _ 7 
// _ 8 8 까지의 갯수는 _ 8까지의 갯수와 같다.(if 조건으로 구현)
//그래서 만든 점화식이 dp[i][j]=dp[i-1][j]+dp[i][j-1];
#include <iostream>
using namespace std;
int N, result, dp[1001][10];

int main() {
	scanf("%d", &N);
	for (int i = 0; i < 10; i++) {
		dp[1][i] = 1;
	}
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0) dp[i][j] = dp[i - 1][j];
			else {
				dp[i][j] = (dp[i - 1][j] % 10007 + dp[i][j - 1] % 10007) % 10007;
			}
		}
	}
	for (int j = 0; j < 10; j++) {
		result = (result % 10007 + dp[N][j] % 10007) % 10007;
	}
	printf("%d\n", result);
	return 0;
}
 
