#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll a, b, c, answer = 1;

ll recur(ll a, ll b) {
  if(b == 1) return a % c;
  ll temp = recur(a, b / 2);
  temp = (temp * temp) % c;
  if(b % 2 == 1) temp = (a * temp) % c;
  return temp;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> a >> b >> c;
  cout << recur(a, b) << '\n';
  return 0;
}