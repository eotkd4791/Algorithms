#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int WALL = -1;
const int INF = 987654321;

struct Info {
  int x;
  int y; 
  int p;
  int d;
};

struct Compare {
  bool operator()(const Info& a, const Info& b) {
    return a.p > b.p;
  }
};
Info S, E;
int N, M;
int Field[101][101];
int Dp[101][101][3];
priority_queue<Info, vector<Info>, Compare> PQ;
vector<vector<vector<int> > > Dir
{
  { {-1, 0}, {1, 0}, {0, -1}, {0, 1} },
  { {-1, 0}, {1, 0} },
  { {0, -1}, {0, 1} }
};

bool IsInside(int x, int y) {
  return 1 <= x && x <= N && 1 <= y && y <= M;
}

void Move() {
  PQ.push(S);

  while(!PQ.empty()) {
    Info CurPos = PQ.top();
    int Nd = (CurPos.d + 1) % 3;
    PQ.pop();

    int Size = Dir[Nd].size();
    for(int i = 0; i < Size; i++) {
      int Nx = CurPos.x + Dir[Nd][i][0];
      int Ny = CurPos.y + Dir[Nd][i][1];
      int Np = CurPos.p + Field[Nx][Ny];
      Info NewPos = { Nx, Ny, Np, Nd };

      if(IsInside(Nx, Ny) && Field[Nx][Ny] != WALL && Dp[Nx][Ny][Nd] > Np) {
        Dp[Nx][Ny][Nd] = Np;
        PQ.push(NewPos);
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  cin >> S.x >> S.y >> E.x >> E.y;

  S.p = 0;
  E.p = 0;
  S.d = 0;

  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= M; j++) {
      cin >> Field[i][j];
    }
  }

  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= M; j++) {
      for(int k = 0; k < 3; k++) {
        Dp[i][j][k] = INF;
      }
    }
  }

  Move();

  int Answer = Dp[E.x][E.y][0];
  for(int i=0; i<3; i++) {
    Answer = min(Answer, Dp[E.x][E.y][i]);
  }
  if(Answer == INF) {
    Answer = -1;
  }
  cout << Answer << '\n';
  return 0;
}