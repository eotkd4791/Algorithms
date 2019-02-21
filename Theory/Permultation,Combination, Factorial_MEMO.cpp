//순열Permultation, 조합Combination ,팩토리얼 Factorial
//함수와 공식.
#include<iostream>
using namespace std;
long long dp[1000][1000];
long long _C_, _P_=1;

long long combination(int n, int k) {
	long long &ret = dp[n][k];
	if (k == 1) return n;
	if (n == k) return 1;
	if (k == 0) return 1;
	if (ret > 0) return ret;
	ret = 0;
	ret = combination(n - 1, k - 1) + combination(n - 1, k);
	return ret;
} //이항계수 nCk=n-1Ck-1 + n-1Ck  -  DP

long long Factorial(int n) {
	if (n == 1) return 1;
	return n * Factorial(n - 1);
}//팩토리얼 - 재귀

int main() {
	int N, K = 0;
	scanf("%d%d", &N, &K);

	for (int j = N; j > N - K; j--) _P_ *= j;
	//순열 - 반복문

	_C_ = Factorial(N) / (Factorial(K) * Factorial(N - K)); //기본 공식
	_C_ = _P_ / Factorial(K);								//순열 이용
	//조합 공식
	return 0;
}