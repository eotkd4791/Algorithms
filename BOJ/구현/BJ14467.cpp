#include <iostream>
#include <cstring>
using namespace std;

int N, a, b, ans;
int arr[11];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(arr, -1, sizeof(arr));

  cin >> N;
  for(int i=0; i<N; i++) {
    cin >> a >> b;

    if(arr[a] != -1  && arr[a] != b) {
      ans++;
    }
    arr[a] = b;
  }
  cout << ans;
  return 0;
}