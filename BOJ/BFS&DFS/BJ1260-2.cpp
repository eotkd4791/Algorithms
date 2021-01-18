#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstring>
using namespace std;

int N, M, V;
vector<vector<int> > graph;
queue<int> q;
bool is_visited[1001];

void dfs(int cur) {
  if(is_visited[cur]) return;
  is_visited[cur] = true;
  cout << cur << ' ';
  for(int i=0; i<graph[cur].size(); i++) {
    int next = graph[cur][i];
    if(is_visited[next]) continue;
    dfs(next);
  }
}

void bfs(int start) {
  q.push(start);
  is_visited[start]=true;
  
  while(!q.empty()) {
    int cur = q.front();
    cout << cur << ' ';
    q.pop();

    for(int i=0; i<graph[cur].size(); i++) {
      int next = graph[cur][i];
      if(is_visited[next]) continue;
      is_visited[next]=true;
      q.push(next);
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M >> V;

  graph.resize(N + 1);

  int start, end;
  for(int i=0; i<M; i++) {
    cin >> start >> end;
    
    graph[start].push_back(end);
    graph[end].push_back(start);
  }
  
  for(int i=0; i<N; i++) {
    sort(graph[i].begin(), graph[i].end());
  }

  dfs(V);
  memset(is_visited, 0, sizeof(is_visited));
  cout << '\n';
  bfs(V);
  return 0;
}