#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int arr[21][21];
vector<vector<int> > v;
vector<int> list;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

bool out_of_border(int x, int y)
{
  return 1 > x || x > n || n < y || y < 1;
}

vector<pair<int, int> > fill_if_empty()
{
  vector<pair<int, int> > temp;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (arr[i][j] == 0)
      {
        temp.push_back(make_pair(i, j));
      }
    }
  }
  return temp;
}

vector<pair<int, int> > first_condition(int me)
{
  vector<pair<int, int> > ret;
  int max_mates = 0;

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (arr[i][j] == 0)
      {
        int mate_cnt = 0;
        for (int dir = 0; dir < 4; dir++)
        {
          int nx = i + dx[dir];
          int ny = j + dy[dir];
          if (!out_of_border(nx, ny) && arr[nx][ny] > 0)
          {
            auto iter = find(v[me].begin(), v[me].end(), arr[nx][ny]);
            if (iter != v[me].end())
            {
              mate_cnt++;
            }
          }
        }
        if (max_mates < mate_cnt)
        {
          max_mates = mate_cnt;
          ret.clear();
        }
        if (max_mates <= mate_cnt)
        {
          ret.push_back(make_pair(i, j));
        }
      }
    }
  }
  return ret;
}

vector<pair<int, int> > second_condition(vector<pair<int, int> > seats)
{
  vector<pair<int, int> > ret;
  int max_empty = 0;
  for (auto iter = seats.begin(); iter != seats.end(); iter++)
  {
    int empty_cnt = 0;
    int ox = iter->first;
    int oy = iter->second;

    if (arr[ox][oy] == 0)
    {
      for (int dir = 0; dir < 4; dir++)
      {
        int nx = ox + dx[dir];
        int ny = oy + dy[dir];

        if (!out_of_border(nx, ny) && arr[nx][ny] == 0)
        {
          empty_cnt++;
        }
      }
      if (max_empty < empty_cnt)
      {
        max_empty = empty_cnt;
        ret.clear();
      }
      if (max_empty <= empty_cnt)
      {
        ret.push_back(make_pair(ox, oy));
      }
    }
  }
  return ret;
}

vector<pair<int, int> > third_condition(vector<pair<int, int> > seats)
{
  vector<pair<int, int> > ret = seats;
  sort(ret.begin(), ret.end());
  return ret;
}

int get_score(int cnt)
{
  switch (cnt)
  {
  case 0:
    return 0;
  case 1:
    return 1;
  case 2:
    return 10;
  case 3:
    return 100;
  default:
    return 1000;
  }
}

int get_satisfaction()
{
  int total = 0;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      int me = arr[i][j];
      int cnt = 0;
      for (int dir = 0; dir < 4; dir++)
      {
        int nx = i + dx[dir];
        int ny = j + dy[dir];
        if (!out_of_border(nx, ny))
        {
          int mate = arr[nx][ny];
          auto iter = find(v[me].begin(), v[me].end(), mate);
          if (iter != v[me].end())
          {
            cnt++;
          }
        }
      }
      total += get_score(cnt);
    }
  }
  return total;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  v.resize(n * n + 1);

  int me;
  int mate_i_like;
  for (int i = 1; i <= n * n; i++)
  {
    cin >> me;
    list.push_back(me);
    for (int j = 0; j < 4; j++)
    {
      cin >> mate_i_like;
      v[me].push_back(mate_i_like);
    }
  }

  for (auto iter = list.begin(); iter != list.end(); iter++)
  {
    int me = *iter;
    vector<pair<int, int> > seats_1 = first_condition(me);

    if (seats_1.size() == 1)
    {
      arr[seats_1[0].first][seats_1[0].second] = me;
    }
    else
    {
      if (seats_1.empty())
      {
        seats_1 = fill_if_empty();
      }
      vector<pair<int, int> > seats_2 = second_condition(seats_1);
      if (seats_2.size() == 1)
      {
        arr[seats_2[0].first][seats_2[0].second] = me;
      }
      else
      {
        vector<pair<int, int> > seats_3 = third_condition(seats_2);
        arr[seats_3[0].first][seats_3[0].second] = me;
      }
    }
  }
  int answer = get_satisfaction();
  cout << answer << '\n';
  return 0;
}