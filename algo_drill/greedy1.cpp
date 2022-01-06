#include <iostream>
using namespace std;

int n;
int cnt;
int coin_types[4] = {500, 100, 50, 10};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  for(const int& coin : coin_types) {
    cnt += n / coin;
    n %= coin;
  }
  cout << cnt << '\n';
  return 0;
}