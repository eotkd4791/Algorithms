#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

int N;
pair<int, int> arr[101];
int dp[101];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  pair<int, int> p;
  for(int i=0; i<N; i++) {
    cin >> p.first >> p.second;
    arr[i] = p;
  }

  sort(arr, arr + N);
  fill(dp, dp + N, 1);

  for(int i=0; i<N; i++) {
    for(int j=0; j<i; j++) {
      if(arr[i].second > arr[j].second) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
  }

  int no_need_remove_line = 0;
  for(int i=0; i<N; i++) {
    no_need_remove_line = max(no_need_remove_line, dp[i]);
  }
  cout << N - no_need_remove_line << '\n';
  return 0;
}