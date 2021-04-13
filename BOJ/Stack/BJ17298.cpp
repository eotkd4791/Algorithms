#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

const int MAX = 1000000 + 1;
int n;
int arr[MAX];
int ans[MAX];
stack<int> s;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  memset(ans, -1, sizeof(ans));

  cin >> n;
  for(int i=0; i<n; i++) {
    cin >> arr[i];
  }

  for(int i=0; i<n; i++) {
    while(!s.empty() && arr[i] > arr[s.top()]) {
      ans[s.top()] = arr[i];
      s.pop();
    }
    s.push(i);
  }
  
  for(int i=0; i<n; i++) {
    cout << ans[i] << ' ';
  }
  return 0;
}