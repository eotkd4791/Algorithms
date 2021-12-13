#include <iostream>
#include <utility>
#include <queue>
using namespace std;

const int INF = 2001;
int N;
int field[INF][INF];
bool visit[INF][INF];
int answer;
queue<pair<int,int> > q;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {1, -1, 0, 0};

int changeRange(int a) {
  return (a + 500) * 2;
}

bool isInside(int x, int y) {
  return 0 <= x && x < INF && 0 <= y && y < INF;
}

void bfs(int x, int y) {
  q.push(make_pair(x, y));

  while(!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    for(int dir=0; dir<4; dir++) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if(isInside(nx, ny) && !visit[nx][ny] && field[nx][ny]) {
          visit[nx][ny] = true;
          q.push(make_pair(nx, ny));
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for(int n=0; n<N; n++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int A = changeRange(a);
    int B = changeRange(b);
    int C = changeRange(c);
    int D = changeRange(d);

    for(int i=A; i<=C; i++) {
      field[i][B] = 1;
      field[i][D] = 1;
    }
    for(int i=B; i<=D; i++) {
      field[A][i] = 1;
      field[C][i] = 1;
    }
  }

  bfs(changeRange(0), changeRange(0));
  for(int i=0; i<INF; i++) {
    for(int j=0; j<INF; j++) {
      if(!visit[i][j] && field[i][j]) {
        visit[i][j] = true;
        bfs(i, j);
        answer++;
      }
    }
  }

  cout << answer << '\n';
  return 0;
}