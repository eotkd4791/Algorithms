#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

const int MAX = 1001;
const int INF = 987654321;
int N,M;
int Field[MAX][MAX];
int UpDp[MAX][MAX];
int DownDp[MAX][MAX];

bool OutOfBorder(pair<int, int> position) {
  int x = position.first;
  int y = position.second;
  return 0 > x || x >= N || M <= y || y < 0;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for(int i=0; i<N; i++) {
    fill(UpDp[i], UpDp[i] + M, -INF);
    fill(DownDp[i], DownDp[i] + M, -INF);
    for(int j=0; j<M; j++) {
      cin >> Field[i][j];
    }
  }

  // up
  UpDp[N-1][0] = Field[N-1][0];
  for(int i=N-1; i>=0; i--) {
    for(int j=0; j<M; j++) {
      pair<int, int> FromLeft = make_pair(i, j-1);
      if(!OutOfBorder(FromLeft)) {
        UpDp[i][j] = max(UpDp[i][j], UpDp[FromLeft.first][FromLeft.second] + Field[i][j]);
      }

      pair<int, int> FromBottom = make_pair(i+1, j);
      if(!OutOfBorder(FromBottom)) {
        UpDp[i][j] = max(UpDp[i][j], UpDp[FromBottom.first][FromBottom.second] + Field[i][j]);
      }
    }
  }

  // down
  DownDp[N-1][M-1] = Field[N-1][M-1];
  for(int i=N-1; i>=0; i--) {
    for(int j=M-1; j>=0; j--) {
      pair<int, int> FromRight = make_pair(i, j+1);
      if(!OutOfBorder(FromRight)) {
        DownDp[i][j] = max(DownDp[i][j], DownDp[FromRight.first][FromRight.second] + Field[i][j]);
      }

      pair<int, int> FromBottom = make_pair(i+1, j);
      if(!OutOfBorder(FromBottom)) {
        DownDp[i][j] = max(DownDp[i][j], DownDp[FromBottom.first][FromBottom.second] + Field[i][j]);
      }
    }
  }

  int Answer = -INF;
  for(int i=0; i<N; i++) {
    for(int j=0; j<M; j++) {
      Answer = max(Answer, UpDp[i][j] + DownDp[i][j]);
    }
  }

  cout << Answer << '\n';
  return 0;
}