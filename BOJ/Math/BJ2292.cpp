#include <iostream>
#define ll long long
using namespace std;

ll n;
ll sum=1;
int cnt=1;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  while(sum < n) sum += (cnt++) * 6;
  
  cout << cnt << '\n';;
  return 0;
}