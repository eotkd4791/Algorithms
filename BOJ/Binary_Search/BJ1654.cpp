#include <iostream>
#include <climits>
#define ll long long
using namespace std;

int n, k;
int arr[10001];
ll l = 1;
ll r = INT_MAX;
ll ans;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> k >> n;
  for(int i=0; i<k; i++) {
    cin >> arr[i];
  }
  while(l <= r) {
    ll mid = (l + r) / 2;
    ll sum = 0;
    for(int i=0; i<k; i++) {
      sum += arr[i] / mid;
    }
    if(sum >= n) {
      l = mid + 1;
      ans = mid;
    }
    else {
      r = mid - 1;
    }
  }
  cout << ans << '\n';
  return 0;
}