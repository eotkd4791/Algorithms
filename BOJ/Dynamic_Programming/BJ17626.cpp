#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 50000;
int N;
int dp[MAX + 1];

void FillSquares() {
  memset(dp, -1, sizeof(dp));
  for(int i=1; i<=sqrt(MAX); i++) {
    if(i * i <= MAX) {
      dp[i * i] = 1;
    }
  }
}

int recur(int n) {
  if(n <= 1) {
    return n;
  }
  if(dp[n] > 0) {
    return dp[n];
  }
  for(int i=sqrt(n); i>=1; i--) {
    int square = i * i;
    int count = recur(n - square) + recur(square);

    dp[n] = dp[n] == -1
      ? count
      : dp[n] = min(dp[n], count);
  }
  return dp[n];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  FillSquares();
  cout << recur(N) << '\n';
  return 0;
}