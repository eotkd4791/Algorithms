#include <iostream>
#include <utility>
#include <cstring>
using namespace std;

int N;
char Dir[102];
pair<int, int> CurPos = {1, 1};

bool OutOfBorder(int x, int y) {
  return 1 > x || x > N || N < y || y < 1;
}

pair<int, int> nextPos(char D) {
  switch(D) {
    case 'L': return {0, -1};
    case 'R': return {0, 1};
    case 'U': return {-1, 0};
    default: return {1, 0};
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  cin.ignore();
  cin.getline(Dir, 100);

  for(int i=0; i<strlen(Dir); i++) {
    if(Dir[i] != ' ') {
      int Nx = CurPos.first + nextPos(Dir[i]).first;
      int Ny = CurPos.second + nextPos(Dir[i]).second;

      if(!OutOfBorder(Nx, Ny)) {
        CurPos = {Nx, Ny};
      }
    }
  }

  cout << CurPos.first << ' ' << CurPos.second << '\n';
  return 0;
}