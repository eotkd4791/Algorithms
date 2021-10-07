#include <iostream>
#include <algorithm>
#include <utility>
#include <cmath>
#define LIMIT 1000000000
using namespace std;

int n;
int arr[100000];
int ans[2]={LIMIT, LIMIT};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i=0; i<n; i++) {
    cin >> arr[i];
  }

  sort(arr, arr + n);
  
  int left = 0;
  int right = n-1;
  while(left < right) {
    if(abs(arr[left] + arr[right]) < abs(ans[0] + ans[1])) {
      ans[0] = arr[left];
      ans[1] = arr[right];
    }
    if(arr[left] + arr[right] < 0) {
      left++;
    } else {
      right--;
    }
  }

  cout << ans[0] << ' ' << ans[1] << '\n';
  return 0;
}