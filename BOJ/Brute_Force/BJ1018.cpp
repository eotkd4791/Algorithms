#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
char field[50][50];
char WW[8][8];
char BB[8][8];
int MIN = 987654321;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for(int i=0; i<N; i++) {
    for(int j=0; j<M; j++) {
      cin >> field[i][j];
    }
  }
  
  for(int i=0; i<8; i++) {
    for(int j=0; j<8; j++) {
      if((i + j) % 2 == 0) {
        WW[i][j] = 'W';
        BB[i][j] = 'B';
      } else {
        WW[i][j] = 'B';
        BB[i][j] = 'W';
      }
    }
  }

  for(int i=0; i<N; i++) {
    for(int j=0; j<M; j++) {
      if(i+8 <= N && j+8 <= M) {
        int wcnt=0;
        int bcnt=0;
        for(int k=0; k<8; k++) {
          for(int l=0; l<8; l++) {
            if(field[i+k][j+l] != WW[k][l]) {
              wcnt++;
            }
            if(field[i+k][j+l] != BB[k][l]) {
              bcnt++;
            }
          }
        }
        MIN = min(min(MIN, bcnt), wcnt);
      }
    }
  }
  cout << MIN << '\n';
  return 0;
}