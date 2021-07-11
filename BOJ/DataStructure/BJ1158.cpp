#include <iostream>
#include <queue>
#include <string>
using namespace std;

int n;
int k;
string answer = "<";
queue<int> q;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;

  for (int i = 1; i <= n; i++)
  {
    q.push(i);
  }

  while (!q.empty())
  {
    for (int i = 1; i < k; i++)
    {
      q.push(q.front());
      q.pop();
    }
    answer += to_string(q.front());
    q.pop();

    answer += !q.empty() ? ", " : ">";
  }
  cout << answer << "\n";
  return 0;
}