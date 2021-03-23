#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1000 + 1;
int N;
int A[MAX];
int dp[MAX][2];
int ans;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for(int i=0; i<N; i++) {
    cin >> A[i];
    dp[i][0] = 1;
    dp[i][1] = 1;
  }

  for(int i=0; i<N; i++) {
    for(int j=0; j<i; j++) {
      if(A[i] > A[j]) {
        dp[i][0] = max(dp[i][0], dp[j][0] + 1);
      }
    }
  }

  for(int i=N-1; i>=0; i--) {
    for(int k=N-1; k>i; k--) {
      if(A[i] > A[k]) {
        dp[i][1] = max(dp[i][1], dp[k][1] + 1);
      }
    }
  }

  for(int i=0; i<N; i++) {
    ans = max(ans, dp[i][0] + dp[i][1]);
  }
  cout << ans - 1 << '\n';
  return 0;
}