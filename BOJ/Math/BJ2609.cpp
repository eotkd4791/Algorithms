#include <iostream>
using namespace std;

int A, B;

int GCD(int a, int b) {
  return b ? GCD(b, a % b) : a;
}

int LCM(int a, int b) {
  return a * b / GCD(a, b);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> A >> B;
  cout << GCD(A, B) << '\n' << LCM(A, B);
  return 0;
}