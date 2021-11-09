#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
const int INF = 10001;
int Coins[101];
int Dp[INF];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> K;
  for(int i=1; i<=N; i++) {
    cin >> Coins[i];
  }

  for(int i=1; i<=K; i++) {
    Dp[i] = INF;
  }
  
  for(int i=1; i<=N; i++) {
    for(int j=Coins[i]; j<=K; j++) {
      Dp[j] = min(Dp[j], Dp[j-Coins[i]] + 1);
    }
  }

  cout << (Dp[K] == INF ? -1 : Dp[K]) << '\n';
  return 0;
}