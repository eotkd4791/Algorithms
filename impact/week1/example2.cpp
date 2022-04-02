#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string dopa = "life is limited";
  cout << dopa.substr(0, 3) << '\n';

  reverse(dopa.begin(), dopa.end());
  cout << dopa << '\n';

  dopa += "dopa!!";
  cout << dopa << '\n';
  return 0;
}