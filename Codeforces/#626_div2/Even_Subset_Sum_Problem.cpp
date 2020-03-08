#include <iostream>
#include <vector>
using namespace std;

int main()
{
  ios::sync_with_stdio(0); cin.tie(0);
  
  int T, n;

  cin >> T;
  
  while(T--)
  {
    int arr[101]={}; vector<int> v;
    
    cin >> n;
    
    bool evenNum = false; int idx = 0;
    
    for(int i = 0; i < n; i++)
    {
      cin >> arr[i];
      
      if(arr[i] % 2 == 0)
      {
        evenNum = true;
        idx = i + 1;
      }
      else
      {
        v.push_back(i + 1);
      }
    }
      
    if(!evenNum)
    {
      if(v.size() > 1)
      {
        cout << 2 << '\n';
        for(int i=0; i<2; i++)
        {
          cout << v[i] << ' ';
        }
        cout << '\n';
      }
      else
      {
      cout << -1 << '\n';
      }
    }
    else
    {
      cout << 1 << '\n' << idx << '\n';
    }
  }
  return 0;
}
