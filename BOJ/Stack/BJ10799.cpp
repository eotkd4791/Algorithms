#include <iostream>
#include <stack>
using namespace std;

string Stick;
stack<char> S;
int Answer;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> Stick;

  if(Stick[0] == '(') {
    S.push('(');
  }

  for(int i=1; i<Stick.size(); i++) {
    if(Stick[i] == ')') {
      S.pop();
      if(Stick[i-1] == '(') {
        if(!S.empty()) {
          Answer += S.size();
        }
      }
      else {
        Answer++;
      }
    }
    else {
      S.push(Stick[i]);
    }
  }
  cout << Answer << '\n';
  return 0;
}