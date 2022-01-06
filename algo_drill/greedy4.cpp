#include <iostream>
using namespace std;

int N, K, Answer;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> K;

  while(true) {
    if(N == 1) {
      break;
    }
    if(N % K == 0) {
      N /= K;
    }
    else {
      N--;
    }
    Answer++;
  }
  cout << Answer << '\n';
  return 0;
}