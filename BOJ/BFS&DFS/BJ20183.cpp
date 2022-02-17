#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>

#define ll long long
#define INF 1000000000000000
using namespace std;

struct Compare {
  bool operator()(pair<ll, ll> a, pair<ll, ll> b) {
    return a.second > b.second;
  }
};

ll N, M, A, B, C, Answer = -1;
vector<vector<pair<ll, ll> > > Graph;
vector<ll> Dist;
priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, Compare> PQ;

bool Dijkstra(ll Max) {
  fill(Dist.begin(), Dist.end(), INF);
  Dist[A] = 0;

  PQ.push({ A, 0 });

  while(!PQ.empty()) {
    pair<ll, ll> Cur = PQ.top();
    PQ.pop();

    if(Dist[Cur.first] < Cur.second) {
      continue;
    }

    int Size = (int) Graph[Cur.first].size();
    for(int i = 0; i < Size; i++) {
      pair<ll, ll> Next = Graph[Cur.first][i];
      if(Max >= Next.second && Dist[Next.first] > Dist[Cur.first] + Next.second) {
        Dist[Next.first] = Dist[Cur.first] + Next.second;
        PQ.push({ Next.first , Dist[Next.first] });
      }
    }
  }
  return Dist[B] <= C;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M >> A >> B >> C;

  Graph.resize(N + 1);
  Dist.resize(N + 1);

  ll a, b, c;
  for(int i = 0; i < M; i++) {
    cin >> a >> b >> c;
    Graph[a].push_back({ b, c });
    Graph[b].push_back({ a, c });
  }

  ll left = 1;
  ll right = INF;

  while(left <= right) {
    ll mid = (left + right) / 2;

    if(Dijkstra(mid)) {
      Answer = mid;
      right = mid - 1;
    }
    else {
      left = mid + 1;
    }
  }

  cout << Answer << '\n';
  return 0;
}