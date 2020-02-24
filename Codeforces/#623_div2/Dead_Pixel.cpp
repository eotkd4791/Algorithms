#include <iostream>
#include <algorithm>
using namespace std;
  
int main()
{
  ios::sync_with_stdio(0); cin.tie(0);
  
  int T,a,b,x,y;
  
  cin >> T;
  
  while(T--)
  {
    cin >> a >> b >> x >> y;
    
    int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;

    sum1 = x * b;

    sum2 = a * y;

    sum3 = a * (b - 1 - y);

    sum4 = (a - 1 - x) * b;
    
    cout << max(max(max(sum1, sum2), sum3), sum4) << '\n';
  }
  return 0;
}