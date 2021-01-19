#include <iostream>
using namespace std;

int V, E, cnt;
int parent[101];

int find(int u) {
  if(parent[u] == u) return u;
  return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
  int uu = find(u);
  int vv = find(v);

  if(uu == 1) parent[vv] = uu;
  else parent[uu] = vv;

  for(int i=1; i<=V; i++) find(i);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> V >> E;

  for(int i=1; i<=V; i++) {
    parent[i] = i;
  }

  int a, b;
  for(int i=0; i<E; i++) {
    cin >> a >> b;
    merge(a, b);
  }

  for(int i=1; i<=V; i++) {
    if(parent[i] == 1) {
      cnt++;
    }
  }
  cout << cnt-1 << '\n';
  return 0;
}