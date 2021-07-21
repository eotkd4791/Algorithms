#include <iostream>
#include <queue>
#include <cmath>
#include <utility>
using namespace std;

int n;
int field[1001][1001];
bool visit[1001][1001];
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

void init_visit()
{
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      visit[i][j] = false;
    }
  }
  visit[1][1] = true;
}

bool is_inside(int x, int y)
{
  return 1 <= x && x <= n && 1 <= y && y <= n;
}

bool can_go(int height)
{
  queue<pair<int, int> > q;
  init_visit();
  q.push(make_pair(1, 1));

  while (!q.empty())
  {
    int ox = q.front().first;
    int oy = q.front().second;

    q.pop();

    for (int dir = 0; dir < 4; dir++)
    {
      int nx = ox + dx[dir];
      int ny = oy + dy[dir];

      if (is_inside(nx, ny) && !visit[nx][ny] && abs(field[nx][ny] - field[ox][oy]) <= height)
      {
        if (nx == n && ny == n)
        {
          return true;
        }
        visit[nx][ny] = true;
        q.push(make_pair(nx, ny));
      }
    }
  }
  return false;
}

int solution()
{
  int left = 0;
  int right = 1000000000;
  int answer = 0;

  while (left <= right)
  {
    int mid = (left + right) / 2;

    if (can_go(mid))
    {
      right = mid - 1;
      answer = mid;
    }
    else
    {
      left = mid + 1;
    }
  }
  return answer;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      cin >> field[i][j];
    }
  }
  cout << solution() << '\n';
  return 0;
}