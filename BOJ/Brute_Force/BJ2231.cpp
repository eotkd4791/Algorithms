#include <iostream>
using namespace std;

int N;
bool flag;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  for(int i=1; i<=N; i++) {
    int sum = 0;
    int temp = i;

    while(temp > 0) {
      sum += temp % 10;
      temp /= 10;
    }
    
    if(i+sum == N) {
      cout << i << '\n';
      flag = true;
      break;
    }
  }
  if(!flag) cout << '0' << '\n';
  return 0;
}