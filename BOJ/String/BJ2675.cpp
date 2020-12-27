#include <iostream>
#include <string>
using namespace std;

int T, R;
string S;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;

  while (T--)
  {
    cin >> R >> S;

    string res;

    for (int j = 0; j < S.size(); j++)
    {
      for (int i = 0; i < R; i++)
      {
        res += S[j];
      }
    }
    cout << res << '\n';
  }
  return 0;
}
