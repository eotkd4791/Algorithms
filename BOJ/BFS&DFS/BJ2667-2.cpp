#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

int N;
char field[26][26];
bool check[26][26];
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};
vector<int> ans;

bool OOB(int x, int y) {
  return 0 <= x && x < N && N > y && y >= 0;
}

void bfs(int x, int y) {
  int cnt = 1;
  queue<pair<int,int> > q;
  q.push(make_pair(x, y));
  check[x][y] = true;

  while(!q.empty()) {
    pair<int,int> cur = q.front();
    q.pop();

    for(int dir=0; dir<4; dir++) {
      int nx = cur.first + dx[dir];
      int ny = cur.second + dy[dir];

      if(OOB(nx, ny) && !check[nx][ny] && field[nx][ny]=='1') {
        check[nx][ny] = true;
        q.push(make_pair(nx,ny));
        cnt++;
      }
    }
  }
  ans.push_back(cnt);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  
  for(int i=0; i<N; i++) {
    for(int j=0; j<N; j++) {
      cin >> field[i][j];
    }
  }

  for(int i=0; i<N; i++) {
    for(int j=0; j<N; j++) {
      if(field[i][j] == '1' && !check[i][j]) {
        bfs(i, j);
      }
    }
  }
  sort(ans.begin(), ans.end());

  int size = (int) ans.size();
  cout << size << '\n';
  for(int i=0; i<size; i++) cout << ans[i] << '\n';
  return 0;
}