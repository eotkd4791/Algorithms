#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int N, K, a, b;
int Dp[101][100001];
vector<pair<int, int> > Products;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> K;
  for(int i = 0; i < N; i++) {
    cin >> a >> b;
    Products.push_back(make_pair(a, b));
  }

  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= K; j++) {
      if(j >= Products[i - 1].first) {
        Dp[i][j] = max(Dp[i - 1][j], Dp[i - 1][j - Products[i - 1].first] + Products[i - 1].second);
      } else {
        Dp[i][j] = Dp[i - 1][j];
      }
    }
  }
  cout << Dp[N][K] << '\n';
  return 0;
}