#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  int arr[200002] = {};

  cin >> n >> m;

  for (int i = 0; i < n; i++)
    cin >> arr[i];

  if (n > m)
    cout << 0 << '\n';
  else
  {
    int res = 1;
    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        int tmp = abs(arr[i] - arr[j]);
        res = ((res % m) * (tmp % m)) % m;
      }
    }
    cout << res << '\n';
  }
  return 0;
}
