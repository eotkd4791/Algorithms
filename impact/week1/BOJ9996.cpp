#include <bits/stdc++.h>
using namespace std;

int n;
string p, a;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> p;
  
  int star = p.find('*');
  string prefix = p.substr(0, star);
  string suffix = p.substr(star + 1);

  while(n--) {
    cin >> a;
  
    if(prefix.size() + suffix.size() > a.size()) {
      cout << "NE\n";
    } else {
      if(prefix == a.substr(0, prefix.size()) && suffix == a.substr(a.size() - suffix.size())) {
        cout << "DA\n";
      }
      else {
        cout << "NE\n";
      } 
    }
  }
  return 0;
}