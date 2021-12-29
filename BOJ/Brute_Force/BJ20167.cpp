#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int Foods[25];
int Answer;

void recur(int Position, int Satisfaction, int Sum, bool Eaten) {
  if(Position == N) {
    int TotalSatisfaction = Satisfaction;
    if(Sum >= K) {
      TotalSatisfaction += (Sum - K);
    }
    Answer = max(Answer, TotalSatisfaction);
    return;
  }

  int EatenSum = Sum;
  int EatenSatisfaction = Satisfaction;
  bool HasEaten = Eaten;

  if(EatenSum >= K) {
    EatenSatisfaction += (EatenSum - K);
    EatenSum = 0;
    HasEaten = false;
  }

  if(HasEaten) {
    recur(Position + 1, EatenSatisfaction, EatenSum + Foods[Position], true);
    return;
  } 
  recur(Position + 1, EatenSatisfaction, EatenSum + Foods[Position], true);
  recur(Position + 1, EatenSatisfaction, EatenSum, false);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> K;
  for(int i=0; i<N; i++) {
    cin >> Foods[i];
  }
  recur(0, 0, 0, false);
  cout <<  Answer << '\n';
  return 0;
}