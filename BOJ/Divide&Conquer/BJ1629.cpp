#include <iostream>
using namespace std;

typedef long long ll;

ll A, B, C;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> A >> B >> C;

  ll ans = 1;
  ll mod = A % C;
  
  while(B>0) {
    if(B%2) {
      ans *= mod;
      ans %= C;
    }
    mod = ((mod % C) * (mod % C)) % C;
    B /= 2;
  }
  cout << ans << '\n';
  return 0;
}