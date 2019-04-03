////////////////////////////
/*
     BOJ2156 포도주 시식
                          */
////////////////////////////

#include <iostream>
#include <algorithm>
#define MAX 10000
using namespace std;

int N;
int arr[MAX + 1];
int dp[MAX + 1];

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &arr[i]);
	}
	
	dp[1] = arr[1];
	dp[2] = dp[1] + arr[2];

	for (int i = 3; i <= N; i++) {
		dp[i] = max(max(dp[i - 3] + arr[i - 1] + arr[i], dp[i - 1]), dp[i - 2] + arr[i]);
	}
	//dp[0]=0 , dp[1]=arr[1] , dp[2]=dp[1]+arr[2]
	//   1      2      3
	//	 x      o      o	dp[i-3] + arr[i-1] + arr[i]
	//   o      x      o	dp[i-2] + arr[i]
	//   o      o      x	dp[i-1]
	printf("%d\n", dp[N]);
	return 0;
}