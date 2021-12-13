#include <iostream>
#include <utility>
#include <queue>
using namespace std;

const int INF = 2001;
int N;
int Field[INF][INF];
bool Visit[INF][INF];
int Answer;
queue<pair<int, int> > Q;
const int Dx[] = {0, 0, -1, 1};
const int Dy[] = {1, -1, 0, 0};

int ChangeRange(int a) {
  return (a + 500) * 2;
}

bool IsInside(int x, int y) {
  return 0 <= x && x < INF && 0 <= y && y < INF;
}

void BFS(int x, int y) {
  Q.push(make_pair(x, y));

  while(!Q.empty()) {
    int x = Q.front().first;
    int y = Q.front().second;
    Q.pop();

    for(int dir = 0; dir < 4; dir++) {
      int nx = x + Dx[dir];
      int ny = y + Dy[dir];
      if(IsInside(nx, ny) && !Visit[nx][ny] && Field[nx][ny]) {
          Visit[nx][ny] = true;
          Q.push(make_pair(nx, ny));
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for(int n = 0; n < N; n++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int A = ChangeRange(a);
    int B = ChangeRange(b);
    int C = ChangeRange(c);
    int D = ChangeRange(d);

    for(int i = A; i <= C; i++) {
      Field[i][B] = 1;
      Field[i][D] = 1;
    }
    for(int i = B; i <= D; i++) {
      Field[A][i] = 1;
      Field[C][i] = 1;
    }
  }

  BFS(ChangeRange(0), ChangeRange(0));
  for(int i = 0; i < INF; i++) {
    for(int j = 0; j < INF; j++) {
      if(!Visit[i][j] && Field[i][j]) {
        Visit[i][j] = true;
        BFS(i, j);
        Answer++;
      }
    }
  }

  cout << Answer << '\n';
  return 0;
}