#include <iostream>
using namespace std;

int N;
int dp[1001];
const int MOD = 10007;

int recur(int n) {
  if (n <= 2) {
    return (dp[n] = n);
  }

  if (dp[n] > 0) {
    return dp[n];
  }
  return (dp[n] = ((recur(n - 1) % MOD) + (recur(n - 2) % MOD)) % MOD);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> N;
  cout << recur(N) << '\n';
  return 0;
}