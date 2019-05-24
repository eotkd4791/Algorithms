//////////////////////////////
/*
      BOJ1912 ¿¬¼ÓÇÕ
                            */
//////////////////////////////
#include <iostream>
#include <algorithm>
#define INF 100001
using namespace std;

int N;
int arr[INF];
int dp[INF];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	dp[0] = arr[0];
	for (int i = 1; i < N; i++) {
		dp[i] = max(arr[i], dp[i-1] + arr[i]);
	}

	int MAX = dp[0];
	for (int i = 0; i < N; i++) {
		MAX = max(MAX, dp[i]);
	}
	cout << MAX;
	return 0;
}
