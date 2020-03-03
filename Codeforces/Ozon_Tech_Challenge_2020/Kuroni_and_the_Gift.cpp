#include <iostream>
#include <algorithm>
using namespace std;

int T, n;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;
  while (T--)
  {
    int a[101] = {}, b[101] = {};

    cin >> n;
    for (int i = 0; i < n; i++)
      cin >> a[i];
    for (int i = 0; i < n; i++)
      cin >> b[i];

    sort(a, a + n);
    sort(b, b + n);

    for (int i = 0; i < n; i++)
      cout << a[i] << ' ';
    cout << '\n';
    for (int i = 0; i < n; i++)
      cout << b[i] << ' ';

    cout << '\n';
  }
  return 0;
}
