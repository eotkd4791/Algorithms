#include <iostream>
#include <utility>
#include <queue>
#include <algorithm>
#define MAX 1501
using namespace std;

int R,C;
char field[MAX][MAX];
int iceberg[MAX][MAX];
const int dx[4] = {0,0,-1,1};
const int dy[4] = {1,-1,0,0};
pair<int, int> swan[2];

bool OOB(int x, int y) {
  return 0 <= x && x < R && C > y && y >= 0;
}

void number_iceberg() {
  queue<pair<int,int> > q;

  for(int i=0; i<R; i++) {
    for(int j=0; j<C; j++) {
      if(field[i][j] == 'X') {
        for(int dir=0; dir<4; dir++) {
          int nx = i + dx[dir];
          int ny = j + dy[dir];
          if(OOB(nx,ny) && field[nx][ny] != 'X') {
            iceberg[i][j] = 1;
            q.push(make_pair(i, j));
            break;
          }
        }
      }
    }
  }

  while(!q.empty()) {
    pair<int,int> cur = q.front();
    q.pop();

    for(int dir=0; dir<4; dir++) {
      int nx = cur.first + dx[dir];
      int ny = cur.second + dy[dir];

      if(OOB(nx,ny) && field[nx][ny] == 'X') {
        if(iceberg[nx][ny] == 0) {
          iceberg[nx][ny] = iceberg[cur.first][cur.second] + 1;
          q.push(make_pair(nx, ny));
        }
      }
    }
  }
}

bool bfs(int mid) {
  bool visit[MAX][MAX] = {};
  queue<pair<int, int> > q;

  q.push(swan[0]);
  visit[swan[0].first][swan[0].second] = true;

  while(!q.empty()) {
    pair<int,int> cur = q.front();
    q.pop();

    for(int dir=0; dir<4; dir++) {
      int nx = cur.first + dx[dir];
      int ny = cur.second + dy[dir];

      if(OOB(nx,ny) && !visit[nx][ny]) {
        if(mid >= iceberg[nx][ny]) {
          pair<int,int> next = make_pair(nx,ny);

          if(swan[1] == next) return true;

          visit[nx][ny] = true;
          q.push(next);
        }
      }
    }
  }
  return false;
}

int binary_search(int start, int end) {
  int left = start;
  int right = end;
  int ans = end;
  
  while(left <= right) {
    int mid = (left + right) / 2 ;
    
    if(bfs(mid)) {
      right = mid - 1;
      ans = mid;
    }
    else left = mid + 1;
  }
  return ans;
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> R >> C;

  int idx = 0;
  for(int i=0; i<R; i++) {
    for(int j=0; j<C; j++) {
      cin >> field[i][j];
      if(field[i][j] == 'L') swan[idx++] = make_pair(i, j);
      if(field[i][j] != 'X') iceberg[i][j] = -1;
    }
  }

  number_iceberg();
  cout <<  binary_search(0, MAX) << '\n';
  return 0;
}
