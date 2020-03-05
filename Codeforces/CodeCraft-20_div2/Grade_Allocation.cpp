#include <iostream>
using namespace std;

int main() 
{
  ios::sync_with_stdio(0); cin.tie(0);
  
  int T, n, m;

  cin >> T;

  while(T--) 
  {
    int a[1001]={};
    cin >> n >> m;
    
    int sum = 0;
    for(int i = 0; i < n; i++) 
    {
      cin >> a[i];

      sum+=a[i];
    }
    if(m > sum) cout << sum << '\n';
    
    else cout << m << '\n';
  }
  return 0;
}

