#include <iostream>
using namespace std;

int N, K, Answer;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> K;

  while(true) {
    int Target = N % K;
    Answer += Target;
    N -= Target;

    if(N < K) {
      Answer += (N - 1);
      break;
    }

    Answer++;
    N /= K;
  }
  cout << Answer << '\n';
  return 0;
}