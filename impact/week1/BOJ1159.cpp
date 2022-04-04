#include <bits/stdc++.h>
using namespace std;

int N;
map<char, vector<string>> m;
string p, answer;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  for(int i=0; i<N; i++) {
    cin >> p;
    if(m.find(p[0]) == m.end()) m.insert({p[0], vector<string>(1, p)});
    else m[p[0]].push_back(p);
  }

  for(const auto& ps : m) {
    int size = (int) ps.second.size();
    if(size >= 5) answer += ps.first;
  }

  if((int) answer.size() > 0) {
    sort(answer.begin(), answer.end());
    cout << answer << '\n';
  } 
  else cout << "PREDAJA" << '\n';
  return 0;
}