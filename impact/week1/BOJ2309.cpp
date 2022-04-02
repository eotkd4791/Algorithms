#include <bits/stdc++.h>
using namespace std;

int heights[9];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for(int i=0; i<9; i++) {
    cin >> heights[i];
  }

  sort(heights, heights + 9);
  do {
    int sum = 0;
    for(int i=0; i<7; i++) {
      sum += heights[i];
    }
    if(sum == 100) {
      for(int i=0; i<7; i++) {
        cout << heights[i] << '\n';
      }
      break;
    }
  } while(next_permutation(heights, heights + 9));
  return 0;
}