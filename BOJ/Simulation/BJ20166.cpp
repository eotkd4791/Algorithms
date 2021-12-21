#include <iostream>
#include <map>
using namespace std;

int N, M, K;
char Board[15][15];
bool Visit[15][15];
string StringGodLikes[1001];
int Answer[1001];
const int Dx[] = { 0, 0, 1, -1, -1, -1, 1, 1 };
const int Dy[] = { 1, -1, 0, 0, -1, 1, -1, 1 };
map<string, int> Map;

pair<int, int> Rearrange(int Tx, int Ty) {
  int Nx = Tx;
  int Ny = Ty;

  if(Nx == 0) {
    Nx = N;
  }
  if(Nx == N + 1) {
    Nx = 1;
  }
  if(Ny == 0) {
    Ny = M;
  }
  if(Ny == M + 1) {
    Ny = 1;
  }
  return make_pair(Nx, Ny);
}

void DFS(int Cx, int Cy, int Position, string Str) {
  if(Str.size() > 5) {
    return;
  }

  Map[Str]++;
  for(int Dir = 0; Dir < 8; Dir++){
    int Nx = Cx + Dx[Dir];
    int Ny = Cy + Dy[Dir];

    pair<int, int> NewPosition = Rearrange(Nx, Ny);
    Nx = NewPosition.first;
    Ny = NewPosition.second;

    DFS(Nx, Ny, Position + 1, Str + Board[Nx][Ny]);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M >> K;
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= M; j++) {
      cin >> Board[i][j];
    }
  }

  string S;
  for(int i = 1; i <= N; i++) {
    for(int j = 1; j <= M; j++) {
      DFS(i, j, 0, S + Board[i][j]);
    }
  }

  for(int i = 0; i < K; i++) {
    string Str;
    cin >> Str;
    cout << Map[Str] << '\n'; 
  }
  return 0;
}