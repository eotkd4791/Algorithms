#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int Cows[20001];
int Answer;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for(int i=0; i<N; i++) {
    cin >> Cows[i];
  }

  sort(Cows, Cows + N);

  int Right = N - 1;
  for(int Left=0; Left < N; Left++) {
    if(Cows[Left] > M / 2) {
      break;
    }
    while(Cows[Left] + Cows[Right] > M) {
      Right--;
    }
    Answer += Right - Left;
  }
  cout << Answer << '\n';
  return 0;
}