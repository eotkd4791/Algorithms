#include <iostream>
#include <string>
using namespace std;

int T, H, W, N;

string under_ten(int num) {
  string zero = "0";
  return num >= 10 ? to_string(num) : zero.append(to_string(num));
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;
  for(int t=0; t<T; t++) {
    cin >> H >> W >> N;

    int floor = N % H;
    int room = N / H;

    string res;
    if(floor) res = to_string(floor) + under_ten(room + 1);
    else res = to_string(H) + under_ten(room);

    cout << res << '\n';
  }
  return 0;
}