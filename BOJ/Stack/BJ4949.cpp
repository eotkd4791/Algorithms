#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string str;
  while(1) {
    stack<char> s;
    getline(cin, str);
    if(str[0] == '.' && str.size() == 1) break;
    bool is_pair = true;

    for(int i=0; i<str.size(); i++) {
      if(str[i] == '(' || str[i] == '[') {
        s.push(str[i]);
      }
      else if(str[i] == ')') {
        if(!s.empty() && s.top() == '(') {
          s.pop();
        }
        else {
          is_pair = false;
          break;
        }
      } 
      else if(str[i] == ']') {
        if(!s.empty() && s.top() == '[') {
          s.pop();
        }
        else {
          is_pair = false;
          break;
        }
      }
    }
    if(s.empty() && is_pair) {
      cout << "yes" << '\n';
    }
    else {
      cout << "no" << '\n';
    }
  }
  return 0;
}