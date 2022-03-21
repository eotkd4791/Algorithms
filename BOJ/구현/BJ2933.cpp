#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 987654321;
const int MAX = 100;
const int Dx[] = {0, 0, -1, 1};
const int Dy[] = {1, -1, 0, 0};
int R, C, N, a;
char Field[MAX + 1][MAX + 1];
bool Visit[MAX + 1][MAX + 1];
bool FromLeft = true;
queue<pair<int, int>> Q;
vector<pair<int, int>> Clusters;

bool IsInside(int x, int y) {
  return 0 <= x && x < R && 0 <= y && y < C;
}

bool ThrowStickToMineral(int H) {
  int Height = R - H;
  if(FromLeft) {
    for(int i = 0; i < C; i++) {
      if(Field[Height][i] == 'x') {
        Field[Height][i] = '.';
        return true;
      }
    }
  } 
  else {
    for(int i = C - 1; i >= 0; i--) {
      if(Field[Height][i] == 'x') {
        Field[Height][i] = '.';
        return true;
      }
    }
  }
  return false;
}

void BFS() {
  while(!Q.empty()) {
    int Ox = Q.front().first;
    int Oy = Q.front().second;
    Q.pop();

    for(int Dir = 0; Dir < 4; Dir++) {
      int Nx = Ox + Dx[Dir];
      int Ny = Oy + Dy[Dir];
      if(!Visit[Nx][Ny] && Field[Nx][Ny] == 'x' && IsInside(Nx, Ny)) {
        Visit[Nx][Ny] = true;
        Q.push(make_pair(Nx, Ny));
      }
    }
  }
}

void MineralsInAir() {
  for(int i = 0; i < C; i++) {
    if(Field[R - 1][i] == 'x') {
      Q.push(make_pair(R - 1, i));
      Visit[R - 1][i] = true;
    }
  }
  BFS();
}

int getDist() {
  int Min = INF;
  for(const auto& Mineral : Clusters) {
    int Cnt = 0;
    for(int i = Mineral.first + 1; i < R; i++) {
      if(Field[i][Mineral.second] == 'x') {
        if(Visit[i][Mineral.second]) Min = min(Min, Cnt);
        break;
      }
      else Cnt++;
    }
    if(Cnt > 1) Min = min(Min, Cnt);
  }
  if(Min == INF) return 0;
  return Min;
}

void DropMinerals() {
  for(int i = 0; i < R; i++) {
    for(int j = 0; j < C; j++) {
      if(Field[i][j] == 'x' && !Visit[i][j]) {
        Clusters.push_back(make_pair(i, j));
      }
    }
  }
  int Dist = getDist();
  sort(Clusters.begin(), Clusters.end());
  for(auto iter = Clusters.rbegin(); iter != Clusters.rend(); iter++) {
    int x = iter->first;
    int y = iter->second;
    Field[x][y] = '.';
    Field[x + Dist][y] = 'x';
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> R >> C;
  for(int i = 0; i < R; i++) {
    for(int j = 0; j < C; j++) {
      cin >> Field[i][j];
    }
  }

  cin >> N;
  while(N--) {
    cin >> a;

    if(ThrowStickToMineral(a)) {
      memset(Visit, false, sizeof(Visit));
      Clusters.clear();

      MineralsInAir();
      DropMinerals();
    }
    FromLeft = !FromLeft;
  }
  for(int i = 0; i < R; i++) {
    for(int j = 0; j < C; j++) {
      cout << Field[i][j];
    }
    cout << '\n';
  }
  return 0;
}