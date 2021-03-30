#include <iostream>
#include <string>
using namespace std;

int N;
char map[65][65];
string ans;

void recur(int sx, int sy, int ex, int ey) {
  char initial_color = map[sx][sy];
  bool is_diff = false;

  for(int i=sx; i<ex; i++) {
    for(int j=sy; j<ey; j++) {
      if(initial_color != map[i][j]) {
        is_diff = true;
        break;
      }
    }
    if(is_diff) break;
  }

  if(is_diff) {
    int dx = (sx + ex) / 2;
    int dy = (sy + ey) / 2;

    ans.push_back('(');

    recur(sx, sy, dx, dy);
    recur(sx, dy, dx, ey);
    recur(dx, sy, ex, dy);
    recur(dx, dy, ex, ey);

    ans.push_back(')');
  }
  else {
    ans.push_back(initial_color);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for(int i=0; i<N; i++) {
    for(int j=0; j<N; j++) {
      cin >> map[i][j];
    }
  }

  recur(0, 0, N, N);
  cout << ans << '\n';
  return 0;
}