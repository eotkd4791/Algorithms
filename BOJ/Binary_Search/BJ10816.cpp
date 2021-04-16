#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 500000 + 1;
int n, m, q;
int a[MAX];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i=0; i<n; i++) {
    cin >> a[i];
  }

  sort(a, a + n);

  cin >> m;
  for(int i=0; i<m; i++) {
    cin >> q;

    int* start = lower_bound(a, a + n, q);
    int* end = upper_bound(a, a + n, q);

    cout << end - start << ' ';
  }
  return 0;
}