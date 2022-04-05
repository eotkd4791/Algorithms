#include <bits/stdc++.h>
using namespace std;

int t, n;
string a, b;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); 

  cin >> t;
  while(t--) {
    int answer = 1;
    map<string, int> m;

    cin >> n;
    for(int i = 0; i < n; i++) {
      cin >> a >> b;
      m[b]++;
    }
    for(const auto& p : m) answer *= (p.second + 1);
    cout << answer - 1 << '\n';
  }
  return 0;
}