#include <bits/stdc++.h>
using namespace std;

int N, cnt[26];
string p, answer;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for(int i=0; i<N; i++) {
    cin >> p;
    cnt[p[0] - 'a']++;
  }

  for(int i=0; i<26; i++) if(cnt[i] >= 5) answer += i + 'a';
  if(answer.size()) cout << answer << '\n';
  else cout << "PREDAJA" << '\n';
  return 0;
}