#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 100000 + 1;
long long N, K, Sum, j;
long long Foods[INF];
long long Dp[INF];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> K;
  for(int i = 1; i <= N; i++) {
    cin >> Foods[i];

    Sum += Foods[i];
    Dp[i] = Dp[i-1];

    while(Sum >= K) {
      Dp[i] = max(Dp[i], Dp[j++] + Sum - K);
      Sum -= Foods[j];
    }
  }
  cout << Dp[N] << '\n';
  return 0;
}