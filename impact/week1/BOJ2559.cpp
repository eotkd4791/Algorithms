#include <bits/stdc++.h>
using namespace std;

int n, k, sum, arr[100001];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  for(int i = 0; i < n; i++) cin >> arr[i];
  for(int i = 0; i < k; i++) sum += arr[i];

  int answer = sum;
  for(int i = k; i < n; i++) {
    sum += (arr[i] - arr[i - k]);
    answer = max(answer, sum);
  }
  cout << answer << '\n'; 
  return 0;
}