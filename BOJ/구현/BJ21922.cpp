#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int N, M;
const int MAX = 2000;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
int Field[MAX][MAX];
bool Visit[MAX][MAX][4];
int Answer[MAX][MAX];
queue<pair<int, pair<int, int> > >Q;

bool OutOfBorder(int x, int y) {
  return 0 > x || x >= N || M <= y || y < 0;
}

int GetChangedDirection(int ObjectNumber, int CurrentDir) {
  const int UP = 0, LEFT = 1, DOWN = 2, RIGHT = 3;

  if(ObjectNumber == 1) {
    if(CurrentDir == LEFT || CurrentDir == RIGHT) {
      return (CurrentDir + 2) % 4;
    }
  } else if(ObjectNumber == 2) {
    if(CurrentDir == UP || CurrentDir == DOWN) {
      return (CurrentDir + 2) % 4;
    }
  } else if(ObjectNumber == 3) {
    if(CurrentDir == UP) {
      return RIGHT;
    } else if(CurrentDir == LEFT) {
      return DOWN;
    } else if(CurrentDir == DOWN) {
      return LEFT;
    } else if(CurrentDir == RIGHT) {
      return UP;
    }
  } else if(ObjectNumber == 4) {
    if(CurrentDir == UP) {
      return LEFT;
    } else if(CurrentDir == LEFT) {
      return UP;
    } else if(CurrentDir == DOWN) {
      return RIGHT;
    } else if(CurrentDir == RIGHT) {
      return DOWN;
    }
  }
  return CurrentDir;
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
      nd = GetChangedDirection(Field[nx][ny], nd);
      Q.push(make_pair(nd, make_pair(nx, ny)));
    }
  }
}

void PrintAnswer() {
  int Count = 0;
  for(int i=0; i<N; i++) {
    for(int j=0; j<M; j++) {
      if(Answer[i][j] > 0) {
        Count++;
      }
    }
  }
  cout << Count << '\n';
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
  PrintAnswer();
  return 0;
}