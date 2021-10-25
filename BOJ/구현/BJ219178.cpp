#include <iostream>
using namespace std;

int N, M;
int Bulbs[4001];

void One(int I, int X) {
  Bulbs[I] = X;
}

void Two(int L, int R) {
  for(int i=L; i<=R; i++) {
    Bulbs[i] ^= 1;
  }
}

void Three(int L, int R) {
  for(int i=L; i<=R; i++) {
    Bulbs[i] = 0;
  }
}

void Four(int L, int R) {
  for(int i=L; i<=R; i++) {
    Bulbs[i] = 1;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for(int i=1; i<=N; i++) {
    cin >> Bulbs[i];
  }

  int a, b, c;
  for(int i=0; i<M; i++) {
    cin >> a >> b >> c;
    switch(a) {
      case 1: One(b, c); break;
      case 2: Two(b, c); break;
      case 3: Three(b, c); break;
      case 4: Four(b, c); break;
    }
  }

  for(int i=1; i<=N; i++) {
    cout << Bulbs[i] << ' ';
  }
  return 0;
}