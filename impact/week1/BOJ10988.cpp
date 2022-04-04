#include <bits/stdc++.h>
using namespace std;

string word;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> word;

  string rword = word;
  reverse(rword.begin(), rword.end());

  cout << (word == rword) << '\n';
  return 0;
}