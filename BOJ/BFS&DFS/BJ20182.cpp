#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

struct compare {
  bool operator()(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
  }
};

vector<pair<int, int>> Graph[100001];
priority_queue<pair<int, int>, vector<pair<int, int> >,  compare> PQ;
int N, M, A, B, C, Answer = -1;
int Money[100001];

bool Dijkstra(int Max) {
  for(int i=1; i<=N; i++) {
    Money[i] = 987654321;
  }

  PQ.push({ A, 0 });
  Money[A] = 0;

  while(!PQ.empty()) {
    pair<int, int> Cur = PQ.top();
    PQ.pop();

    if(Money[Cur.first] < Cur.second) {
      continue;
    }

    int size = (int) Graph[Cur.first].size();
    for(int i=0; i<size; i++) {
      pair<int, int> Next = Graph[Cur.first][i];
      if(Max >= Next.second && Money[Next.first] > Money[Cur.first] + Next.second) {
        Money[Next.first] = Money[Cur.first] + Next.second;
        PQ.push({ Next.first, Money[Next.first] });
      }
    }
  }
  return Money[B] <= C;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M >> A >> B >> C;

  int a, b, c;
  for(int i = 0; i < M; i++) {
    cin >> a >> b >> c;
    Graph[a].push_back({ b, c });
    Graph[b].push_back({ a, c });
  }

  for(int i=1; i<=20; i++) {
    if(Dijkstra(i)) {
      Answer = i;
      break;
    }
  }

  cout << Answer << '\n';
  return 0;
}