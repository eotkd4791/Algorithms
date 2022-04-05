#include <bits/stdc++.h>
using namespace std;

string str, answer;
char A[26];
char a[26];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  getline(cin, str);
  for(int i=0; i<26; i++) {
    a[i] = 'a' + i;
    A[i] = 'A' + i;
  }
  rotate(a, a + 13, a + 26);
  rotate(A, A + 13, A + 26);
  
  for(const auto& s : str) {
    if('a' <= s && s <= 'z') answer += a[s - 'a'];
    else if('A' <= s && s <= 'Z') answer += A[s - 'A'];
    else answer += s;
  }

  cout << answer << '\n';
  return 0;
}