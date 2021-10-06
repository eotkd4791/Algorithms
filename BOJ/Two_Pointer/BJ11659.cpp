#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> v;
int arr[1000001];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n >> m;
  for(int i=0; i<n; i++) {
    int a;
    cin >> a;
    v.push_back(a);
  }

  for(int i=0; i<v.size(); i++) {
    arr[i+1] = arr[i] + v[i];
  }
  
  for(int i=0; i<m; i++) {
    int a,b;
    cin >> a >> b;
    cout << arr[b] - arr[a-1] << '\n';
  }
  return 0;
}