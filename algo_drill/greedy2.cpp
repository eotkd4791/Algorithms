#include <iostream>
#include <algorithm>
using namespace std;

int N, M, K;
int Nums[10001];
int Answer;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M >> K;
  for(int i=0; i<N; i++) {  
    cin >> Nums[i];
  }

  sort(Nums, Nums + N);

  int First = Nums[N - 1];
  int Second = Nums[N - 2];

  while(true) {
    for(int i=0; i<K; i++) {
      if(M == 0) {
        break;
      }
      Answer += First;
      M--;
    }
    if(M == 0) {
      break;
    }
    Answer += Second;
    M--;
  }
  cout << Answer << '\n';
  return 0;
}