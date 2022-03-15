#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Graph {
  Graph(int _to, int _weight): to(_to), weight(_weight) {}
  int to;
  int weight;
};

struct Node {
  Node(int _n, int _u): n(_n), u(_u) {}
  int n;
  int u;
};

const int INF = 1000000001; 
int N, Q, p, q, r, k, v;
vector<vector<Graph> > Adj;

int BFS(int k, int v);

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> Q;
  Adj.resize(N + 1);

  for(int i = 0; i < N - 1; i++) {
    cin >> p >> q >> r;
    Adj[p].push_back(Graph(q, r));
    Adj[q].push_back(Graph(p, r)); 
  }

  for(int i = 0; i < Q; i++) {
    cin >> k >> v;
    cout << BFS(k, v) << '\n';
  }
  return 0;
}

int BFS(int k, int v) {
  vector<bool> Visit(N + 1, false);
  queue<Node> Q;
  int Answer = 0;

  Visit[v] = true;
  Q.push(Node(v, INF));

  while(!Q.empty()) {
    Node Cur = Q.front();
    Q.pop();

    for(Graph graph : Adj[Cur.n]) {
      int MinWeight = min(Cur.u, graph.weight);
      int Next = graph.to; 

      if(!Visit[Next] && k <= MinWeight) {
        Answer++;
        Visit[Next] = true;
        Q.push(Node(Next, MinWeight));
      }
    }
  }
  return Answer;
}