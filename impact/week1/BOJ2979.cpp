#include <bits/stdc++.h>
using namespace std;

int a, b, c[3], cnt = -1, sum;
pair<int, int> t[3];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> c[0] >> c[1] >> c[2];
  for(int i = 0; i < 3; i++) {
    cin >> a >> b; 
    t[i] = {a, b};
  }

  sort(t, t + 3);

  for(int ti = 0; ti <=100; ti++) {
    for(int i = 0; i < 3; i++) {
      if(ti == t[i].first) cnt++;
      if(ti == t[i].second) cnt--;
    }
    if(cnt > -1) sum += c[cnt] * (cnt + 1);
  }
  cout << sum;
  return 0;
}