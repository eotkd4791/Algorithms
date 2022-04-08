#include <bits/stdc++.h>
using namespace std;

int n, m, answer, arr[15001];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for(int i = 0; i < n; i++) cin >> arr[i];
  sort(arr, arr + n);
  int left = 0;
  int right = n - 1;

  while(left < right) {
    if(arr[left] + arr[right] < m) left++;
    else if(arr[left] + arr[right] > m) right--;
    else {
      left++; right--;
      answer++;
    }
  }
  cout << answer << '\n';
  return 0;
}