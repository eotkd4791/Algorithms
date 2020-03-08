#include <iostream>
using namespace std;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  char str[1000001] = {};
  int res = 0;
  int n;

  int left = 0, right = 0;

  cin >> n;

  for (int i = 0; i < n; i++)
  {
    cin >> str[i];

    if (str[i] == '(')
      left++;

    else
      right++;
  }

  if (n % 2 == 1 || left != right)
  {
    cout << -1 << '\n';

    return 0;
  }

  left = 0, right = 0;
  bool flag = false;

  for (int i = 0; i < n; i++)
  {
    if (str[i] == '(')
      left++;

    else
      right++;

    if (left < right)
    {
      flag = true;
    }
    else if (left == right)
    {
      if (flag)
        res += left + right;

      left = 0;
      right = 0;

      flag = false;
    }
  }
  cout << res << '\n';
  return 0;
}