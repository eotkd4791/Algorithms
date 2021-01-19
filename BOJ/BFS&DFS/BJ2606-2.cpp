#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<vector<int> > graph;
set<int> s;
int N;
int M;

void dfs(int cur) {
  s.insert(cur);
  
  for(int i=0; i<graph[cur].size(); i++) {
    int next = graph[cur][i];
    if(s.find(next) == s.end()) {
      dfs(next);
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;

  graph.resize(N + 1);

  int a, b;
  for(int i=0; i<M; i++) {
    cin >> a >> b;

    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  dfs(1);
  cout << ((int) s.size() - 1) << '\n';
  return 0;
}