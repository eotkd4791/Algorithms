#include <iostream>
#include <algorithm>
using namespace std;

int N, M, Answer;
int Field[101][101];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for(int i=0; i<N; i++) {
    for(int j=0; j<M; j++) {
      cin >> Field[i][j];
    }
  }

  for(int i=0; i<N; i++) {
    int Temp = 10001;
    for(int j=0; j<M; j++) {
      Temp = min(Temp, Field[i][j]);
    }
    Answer = max(Answer, Temp);
  }
  cout << Answer << '\n';
  return 0;
}