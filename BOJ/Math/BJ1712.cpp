#include <iostream>
using namespace std;

int A,B,C;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> A >> B >> C;
  
  if(B>=C) cout << -1 << '\n';
  else cout << A/(C-B) + 1  << '\n';
  return 0;
}