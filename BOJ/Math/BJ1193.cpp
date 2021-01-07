#include <iostream>
using namespace std;

int X;
int cnt;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> X;

  while(X > 0) {
    cnt++;
    X -= cnt;
  }

  if(cnt % 2 == 0) cout << cnt + X << '/' << 1 + (-X) << '\n';
  else cout << 1 + (-X) << '/' << cnt + X << '\n';
  return 0;
}