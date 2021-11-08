#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int Answer;
int Cows[20001];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> N >> M;
  for(int i=0; i<N; i++) {
    cin >> Cows[i];
  }

  sort(Cows, Cows + N);
  int Right = N - 1;

  for(int i=0; i<N; i++) {
    if(Cows[i] > M / 2) {
      break;
    }
    while(Cows[i] + Cows[Right] > M) {
      Right--;
    }

    Answer += Right - i;
  }
  cout << Answer << '\n';
}