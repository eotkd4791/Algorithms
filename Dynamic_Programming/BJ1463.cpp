#include <iostream>
#include <algorithm>
using namespace std;
int dp[1000001], check[1000001];

int opt(int X) {
	if (X == 1) return 0;
	if (X == 3 || X == 2) return 1;
	if (check[X] != 0) return dp[X];
	else {
		if (X % 2 == 0) {
			check[X] = 1;
			dp[X] = min(opt(X / 2), opt(X - 1)) + 1;
		}
		if (X % 3 == 0) {
			check[X] = 1;
			dp[X] = min(opt(X / 3), opt(X - 1)) + 1;
		}
		if (X % 6 == 0) {
			check[X] = 1;
			dp[X] = min(opt(X / 3), min(opt(X / 2), opt(X - 1))) + 1;
		}
		if (X % 2 != 0 && X % 3 != 0) {
			check[X] = 1;
			dp[X] = opt(X - 1) + 1;
		}
	}
	return dp[X];
}

int main() {
	int N = 0;
	scanf("%d", &N);
	printf("%d\n", opt(N));
	return 0;
}