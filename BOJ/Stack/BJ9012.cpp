#include <iostream>
#include <stack>
#include <string>
using namespace std;

int T;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> T;
  string str;
  for(int i=0; i<T; i++) {
    cin >> str;

    int size = (int) str.size();
    stack<char> s;
    for(int j=0; j<size; j++) {
      if(str[j]=='(') s.push('(');
      else {
        if(s.size() > 0) s.pop();
        else {
          s.push('(');
          break;
        }
      }
    } 

    string ans;
    if(s.size() == 0) ans = "YES";
    else ans = "NO";
    cout << ans << '\n';
  }
  return 0;
}