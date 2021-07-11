#include <iostream>
#include <string>
#include <stack>
using namespace std;

int n;
string answer;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  while (n--)
  {
    string input;
    stack<char> s;

    cin >> input;

    int len = (int)input.size();
    for (int i = 0; i < len; i++)
    {
      if (input[i] == '(')
      {
        s.push(input[i]);
      }
      else if (!s.empty())
      {
        s.pop();
      }
      else
      {
        s.push('(');
        break;
      }
    }
    answer += s.empty() ? "YES\n" : "NO\n";
  }
  cout << answer << '\n';
  return 0;
}