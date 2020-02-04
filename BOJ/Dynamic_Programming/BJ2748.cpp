#include <iostream>
#define endl '\n'
using namespace std;

int N;
long long dp[100];
bool check[100];


long long fib(int n) {
	if (n < 2) return n;

	if (check[n]) return dp[n];
	else {
		check[n] = true;
		return dp[n] = fib(n - 2) + fib(n - 1);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> N;
	cout << fib(N) << endl;
	return 0;
}