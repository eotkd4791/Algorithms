#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() 
{
  ios::sync_with_stdio(0); cin.tie(0);

  int T, n, inp; vector<int> v;

  cin >> T;

  while(T--) 
  {
    cin >> n;

    for(int i = 0; i < n; i++) 
    {
      cin >> inp;

      v.push_back(inp);
    }
    sort(v.begin(), v.end());

    v.erase(unique(v.begin(), v.end()),v.end());

    cout << (int) v.size() << '\n';
  }
    return 0;
};
