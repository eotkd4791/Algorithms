#include <bits/stdc++.h>
using namespace std;

string word, rword;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> word;
  rword = word;

  reverse(rword.begin(), rword.end());
  cout << (word == rword) << '\n';
  return 0;
}