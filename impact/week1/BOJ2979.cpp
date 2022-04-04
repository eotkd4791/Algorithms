#include <bits/stdc++.h>
using namespace std;

int A, B, C, from, to, c[101], sum;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> A >> B >> C;
  for(int i = 0; i < 3; i++) {
    cin >> from >> to;
    for(int j = from; j < to; j++) c[j]++;
  }

  for(int i = 0; i <=100; i++) {
    if(c[i] == 1) sum += A;
    else if(c[i] == 2) sum += 2 * B;
    else if(c[i] == 3) sum += 3 * C;
  }
  cout << sum;
  return 0;
}