#include <bits/stdc++.h>
using namespace std;

int cnt[27];
string S;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> S;
  for(const auto& s : S) {
    cnt[s - 'a']++;
  }

  for(int i=0; i<26; i++) {
    cout << cnt[i] << ' ';
  }
  return 0;
}
