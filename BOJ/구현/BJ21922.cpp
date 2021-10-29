#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int N, M;
const int MAX = 2000;
const int UP = 0;
const int LEFT = 1;
const int DOWN = 2;
const int RIGHT = 3;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
int Field[MAX][MAX];
bool Visit[MAX][MAX][4];
int Answer[MAX][MAX];
queue<pair<int, pair<int, int> > >Q;

bool OutOfBorder(int x, int y) {
  return 0 > x || x >= N || M <= y || y < 0;
}

void BFS() {
  while(!Q.empty()) {
    int CurrentX = Q.front().second.first;
    int CurrentY = Q.front().second.second;
    int CurrentDir = Q.front().first;
    Q.pop();

    int nd = CurrentDir;
    int nx = CurrentX + dx[nd];
    int ny = CurrentY + dy[nd];
    if(!OutOfBorder(nx, ny) && !Visit[nx][ny][nd]) {
      Answer[nx][ny]++;
      Visit[nx][ny][nd] = true;
      
      if(Field[nx][ny] == 1) {
        if(nd == LEFT || nd == RIGHT) {
          nd = (nd + 2) % 4;
        }
      } else if(Field[nx][ny] == 2) {
        if(nd == UP || nd == DOWN) {
          nd = (nd + 2) % 4;
        }
      } else if(Field[nx][ny] == 3) {
        if(nd == UP) {
          nd = RIGHT;
        } else if(nd == LEFT) {
          nd = DOWN;
        } else if(nd == DOWN) {
          nd = LEFT;
        } else if(nd == RIGHT) {
          nd = UP;
        }
      } else if(Field[nx][ny] == 4) {
        if(nd == UP) {
          nd = LEFT;
        } else if(nd == LEFT) {
          nd = UP;
        } else if(nd == DOWN) {
          nd = RIGHT;
        } else if(nd == RIGHT) {
          nd = DOWN;
        }
      }
      Q.push(make_pair(nd, make_pair(nx, ny)));
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for(int i=0; i<N; i++) {
    for(int j=0; j<M; j++) {
      cin >> Field[i][j];
      if(Field[i][j] == 9) {
        Answer[i][j]++;
        for(int Dir=0; Dir<4; Dir++) {
          Visit[i][j][Dir] = true;
          Q.push(make_pair(Dir, make_pair(i, j)));
        }
      }
    }
  }
  BFS();
  int Count = 0;
  for(int i=0; i<N; i++) {
    for(int j=0; j<M; j++) {
      if(Answer[i][j] > 0) {
        Count++;
      }
    }
  }
  cout << Count << '\n';
  return 0;
}