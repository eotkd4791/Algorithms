#include <bits/stdc++.h>
using namespace std;

vector<int> heights;
int a, sum;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for(int i=0; i<9; i++) {
    cin >> a;
    heights.push_back(a);
    sum += a;
  }

  sort(heights.begin(), heights.end());

  bool flag = false;
  pair<int, int> invalidDwarfs;
  for(int i=0; i<9; i++) {
    for(int j=0; j<9; j++) {
      if(i == j) continue;

      if(heights[i] + heights[j] == sum - 100) {
        invalidDwarfs = { heights[i], heights[j] };
        flag = true;
        break;
      }
    }
    if(flag) break;
  }

  for(const auto& height : heights) {
    if(height != invalidDwarfs.first && height != invalidDwarfs.second) {
      cout << height << '\n';
    }
  }
  return 0;
}