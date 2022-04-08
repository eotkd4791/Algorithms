#include <bits/stdc++.h>
using namespace std;

string str, answer;
int cnt[200], odd;
char mid;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> str;
  for(const auto& s : str) cnt[s]++;
  for(int i = 'Z'; i >= 'A'; i--) {
    if(cnt[i] > 0) {
      if(cnt[i] & 1) {
        mid = char(i);
        odd++;
        cnt[i]--;
      }
      if(odd == 2) break;
      for(int j = 0; j < cnt[i]; j += 2) {
        answer = char(i) + answer;
        answer += char(i);
      }
    }
  }
  if(mid) answer.insert(answer.begin() + answer.size() / 2, mid);
  if(odd == 2) cout << "I'm Sorry Hansoo\n";
  else cout << answer << '\n';
  return 0;
}