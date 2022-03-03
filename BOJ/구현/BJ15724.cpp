#include <iostream>
using namespace std;

const int MAX = 1024 + 1;
int N, M, K;
int Board[MAX][MAX];
int Dp[MAX][MAX];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for(int i=1; i<=N; i++) {
    for(int j=1; j<=M; j++) {
      cin >> Board[i][j];
      Dp[i][j] = Board[i][j] + Dp[i-1][j] + Dp[i][j-1] - Dp[i-1][j-1];
    }
  }

  int x1, y1, x2, y2;
  cin >> K;
  for(int i=0; i<K; i++) {
    cin >> x1 >> y1 >> x2 >> y2;
    cout << Dp[x2][y2] - (Dp[x1-1][y2] + Dp[x2][y1-1] - Dp[x1-1][y1-1]) << '\n';
  }
  return 0;
}