#include <bits/stdc++.h>
using namespace std;

int n, answer;
string word;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> word;

    stack<char> s;
    for(const auto& w : word) {
      if(s.empty()) s.push(w); 
      else if(s.top() == w) s.pop();        
      else s.push(w);
    }
    if(s.empty()) answer++;
  }
  cout << answer << '\n';
  return 0;
}