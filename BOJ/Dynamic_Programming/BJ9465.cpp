#include <iostream>
#include <algorithm>
using namespace std;

int T, N;
const int MAX = 100000;
int board[2][MAX+1];
int dp[2][MAX+1];

void Input() {
  cin >> N;
  for(int i=0; i<2; i++) {
    for(int j=0; j<N; j++) {
      cin >> board[i][j];
      dp[i][j] = 0;
    }
  }
}

void Init() {
  dp[0][0] = board[0][0];
  dp[1][0] = board[1][0];
  dp[0][1] = board[0][1] + dp[1][0];
  dp[1][1] = board[1][1] + dp[0][0];
}

void MakeTable() {
  for(int j=2; j<N; j++) {
    for(int i=0; i<2; i++) {
      dp[i][j] = max(
        dp[i][j], 
        max(
          dp[(i + 1) % 2][j-1], 
          max(dp[0][j-2], dp[1][j-2])
        ) + board[i][j]
      );
    }
  }
}

void Answer() {
  cout << max(dp[0][N-1], dp[1][N-1]) << '\n';
}

void Solution() {
  cin >> T;
  while(T--) {
    Input();
    Init();
    MakeTable();
    Answer();
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  Solution();
  return 0;
}