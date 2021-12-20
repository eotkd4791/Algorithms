#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;

int N, M, R, Ax, Ay, Dx, Dy, Score;
char Ad;
int Board[101][101];
char Status[101][101];
int DirX[4] = {0, 0, 1, -1};
int DirY[4] = {1, -1, 0, 0};
queue<pair<int, int> > q;

bool OutOfBorder(int x, int y) {
  return 1 > x || x > N || M < y || y < 1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M >> R;
  for(int i=1; i<=N; i++) {
    for(int j=1; j<=M; j++) {
      cin >> Board[i][j];
    }
  }

  for(int i=0; i<=N; i++) {
    fill(Status[i], Status[i] + M + 1, 'S');
  }

  while(R--) {
    cin >> Ax >> Ay >> Ad;
    cin >> Dx >> Dy;

    if(Status[Ax][Ay] == 'S') {
      q.push(make_pair(Ax, Ay));
      Status[Ax][Ay] = 'F';
      Score++;
    }

    while(!q.empty()) {
      int Cx = q.front().first;
      int Cy = q.front().second;
      q.pop();
      
      int Dir = Ad == 'E' ? 0 : Ad == 'W' ? 1 : Ad == 'S' ? 2 : 3;
      int Dist = Board[Cx][Cy];
      for(int i = 1; i < Dist; i++) {
        int Nx = Cx + (i * DirX[Dir]);
        int Ny = Cy + (i * DirY[Dir]);
        if(OutOfBorder(Nx, Ny) || Status[Nx][Ny] == 'F') {
          continue;
        }
        q.push(make_pair(Nx, Ny));
        Score++;
        Status[Nx][Ny] = 'F';
      }
    }
    Status[Dx][Dy] = 'S';
  } 
  cout << Score << '\n';
  for(int i=1; i<=N; i++) {
    for(int j=1; j<=M; j++) {
      cout << Status[i][j] << ' ';
    }
    cout << '\n';
  }
  return 0;
}