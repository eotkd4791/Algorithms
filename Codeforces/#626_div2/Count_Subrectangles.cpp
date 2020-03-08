#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n = 0, m = 0, k;
  vector<ll> v;

  int a[40001] = {}, b[40001] = {};

  cin >> n >> m >> k;

  int MAX = n > m ? n : m;

  for (int i = 0; i < n; i++)
    cin >> a[i];

  for (int j = 0; j < m; j++)
    cin >> b[j];

  for (int i = 1; i <= k; i++)
  {
    if (i > MAX)
      break;

    if (k / i > MAX)
      continue;

    if (k % i == 0)
      v.push_back(i);
  }

  ll sum = 0;

  for (int h = 0; h < v.size(); h++)
  {
    int left = h, right = (int)v.size() - 1 - h;

    if (v[left] > n || v[right] > m)
      continue;

    ll cnt = 0, nc = 0, mc = 0;

    for (int i = 0; i < n; i++)
    {
      if (a[i] == 1)
      {
        cnt++;
      }
      else
      {
        if (cnt >= v[left])
          nc += cnt - v[left] + 1;

        cnt = 0;
      }
    }
    if (cnt >= v[left])
      nc += cnt - v[left] + 1;

    cnt = 0;

    for (int j = 0; j < m; j++)
    {
      if (b[j] == 1)
        cnt++;
      else
      {
        if (cnt >= v[right])
          mc += cnt - v[right] + 1;

        cnt = 0;
      }
    }
    if (cnt >= v[right])
      mc += cnt - v[right] + 1;

    sum += nc * mc;
  }
  cout << sum << '\n';

  return 0;
}