#include <iostream>
using namespace std;

const int MAX_LEN = 250001;
int N, X;
int Visitors[MAX_LEN];
int Dp[MAX_LEN];
int Answer;
int Count = 1;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> X;
  for(int i=1; i<=N; i++) {
    cin >> Visitors[i];
  }

  for(int i=1; i<=N; i++) {
    Dp[i] = Dp[i-1] + Visitors[i];
  }

  for(int i=0; i<=N-X; i++) {
    int TempAnswer = Dp[i+X] - Dp[i];
    if(Answer < TempAnswer) {
      Count = 1;
      Answer = TempAnswer;
    }
    else if(Answer == TempAnswer) {
      Count++;
    }
  }
  
  if(Answer > 0) {
    cout << Answer << '\n' << Count << '\n';
  } 
  else {
    cout << "SAD" << '\n';
  }
  return 0;
}