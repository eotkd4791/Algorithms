#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

const int INF = 987654321;
int N, M, A, B, C;
int From, To, Cost;
int Answer = INF;
bool Visit[11];
vector<vector<pair<int, int> > > Map;

void DFS(int Position, int Money, int Min) {
  if(Position == B) {
    Answer = min(Answer, Min);
    return;
  }
  
  for(int i=0; i<Map[Position].size(); i++) {
    int NextPosition = Map[Position][i].first;
    int NextCost = Map[Position][i].second;

    if(!Visit[Position] && Money - NextCost >= 0) {
      Visit[Position] = true;
      DFS(NextPosition, Money - NextCost, max(Min, NextCost));
      Visit[Position] = false;
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M >> A >> B >> C;

  Map.resize(N + 1);

  for(int i=0; i<M; i++) {
    cin >> From >> To >> Cost;
    Map[From].push_back(make_pair(To, Cost));
    Map[To].push_back(make_pair(From, Cost));
  }

  DFS(A, C, 0);

  if(Answer == INF) {
    Answer = -1;
  }
  cout << Answer << '\n';
  return 0;
}