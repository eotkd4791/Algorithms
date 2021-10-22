#include <iostream>
using namespace std;

int N;
char Mines[10][10];
char Board[10][10];
int MineCount[10][10];
bool MineOpened;
const int dx[] = {0, 0, 1, -1, -1, -1, 1, 1};
const int dy[] = {1, -1, 0, 0, -1, 1, -1, 1};

bool IsInside(int X, int Y) {
  return 0 <= X && X < N && 0 <= Y && Y < N;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for(int i=0; i<N; i++) {
    for(int j=0; j<N; j++) {
      cin >> Mines[i][j];
    }
  }

  for(int i=0; i<N; i++) {
    for(int j=0; j<N; j++) {
      cin >> Board[i][j];
      if(Board[i][j] == 'x' && Mines[i][j] == '*') {
        MineOpened = true;
      }
    }
  }

  for(int i=0; i<N; i++) {
    for(int j=0; j<N; j++) {
      int MineCountAround = 0;
      for(int Dir=0; Dir<8; Dir++) {
        int nx = i + dx[Dir];
        int ny = j + dy[Dir];

        if(IsInside(nx,ny) && Mines[nx][ny] == '*') {
          MineCountAround++;
        }
      }
      MineCount[i][j] = MineCountAround;
    }
  }

  for(int i=0; i<N; i++) {
    for(int j=0; j<N; j++) {
      if(Board[i][j] == 'x') {
        Board[i][j] = (char) (MineCount[i][j] + 48);
      }
      if(MineOpened && Mines[i][j] == '*') {
        Board[i][j] = '*';
      }
    }
  }

  for(int i=0; i<N; i++) {
    for(int j=0; j<N; j++) {
      cout << Board[i][j];
    }
    cout << '\n';
  }
  return 0;
}