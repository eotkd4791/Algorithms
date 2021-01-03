#include <iostream>
using namespace std;

int dp[21];
int num;

int fib(int n) {
  if(n == 0) return 0;
  if(n <= 2) return 1;

  if(dp[n] > 0) return dp[n];
  else return dp[n] = fib(n-1) + fib(n-2);
} 

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> num;
  cout << fib(num) << '\n';

  return 0;
}