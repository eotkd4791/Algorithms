#include <iostream>
using namespace std;

int T, A, B;

int GCD(int a, int b) {
  return b ? GCD(b, a % b) : a;
}

int LCM(int a, int b) {
  return a * b / GCD(a, b);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;
  while(T--) {
    cin >> A >> B;
    cout << LCM(A, B) << '\n';
  }
  return 0;
}