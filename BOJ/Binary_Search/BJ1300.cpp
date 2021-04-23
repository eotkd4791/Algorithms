#include <iostream>
#include <algorithm>
using namespace std;

int N,K;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> K;

  int left=0;
  int right = (1<<30);
  int ans = 0;
  
  while(left <= right) {
    int mid = (left + right) / 2;
    int cnt = 0;

    for(int i=1; i<=N; i++) {
      cnt += min(N, mid / i);
    }
    if(cnt < K) {
      left = mid + 1;
    } else {
      ans = mid;
      right = mid - 1;
    }  
  }
  cout << ans << '\n';
  return 0;
}