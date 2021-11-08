#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1000000;
int LIMIT;
int N, K;
int Answer;
int Buckets[MAX + 1];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> N >> K;
  for(int i=0; i<N; i++) {
    int g, x;
    cin >> g >> x;
    Buckets[x] = g;
    LIMIT = max(LIMIT, x);
  }

  if(K >= LIMIT) {
    int Answer = 0;
    for(int i=0; i<=LIMIT; i++) {
      Answer += Buckets[i];
    }
    cout << Answer << '\n';
    return 0;
  }

  int Left = 0;
  int Right = 2 * K;

  int Temp = 0;
  for(int i=Left; i<=Right; i++) {
    Temp += Buckets[i];
  }

  for(; Right<LIMIT; Right++) {
    Answer = max(Answer, Temp);
    Temp = (Temp - Buckets[Left++]) + Buckets[Right + 1];
  }
  cout << Answer << '\n';
  return 0;
}