#include <bits/stdc++.h>
using namespace std;

int n, m;
string s;
map<string, int> sn;
map<int, string> ns;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for(int i = 1; i <= n; i++) {
    cin >> s;
    sn[s] = i;
    ns[i] = s;
  }
  for(int i = 0; i < m; i++) {
    cin >> s;
    if('A' <= s[0] && s[0] <= 'Z') cout << sn[s] << '\n';
    else cout << ns[stoi(s)] << '\n';
  }
  return 0;
}