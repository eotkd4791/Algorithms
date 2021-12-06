#include <iostream>
#include <stack>
using namespace std;

string Infix;
stack<char> S;
string Answer;

int Priority(char letter) {
  if(letter == '(') {
    return 0;
  }
  if(letter == '+' || letter == '-') {
    return 1;
  }
  return 2;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> Infix;

  for(int i=0; i<Infix.size(); i++) {
    if('A' <= Infix[i] && Infix[i] <= 'Z') {
      Answer += Infix[i];
    }
    else if('(' == Infix[i]) {
      S.push(Infix[i]);
    }
    else if(')' == Infix[i]) {
      while(!S.empty() && S.top() != '(') {
        Answer += S.top();
        S.pop();
      }
      S.pop();
    }
    else {
      while(!S.empty() && Priority(S.top()) >= Priority(Infix[i])) {
        Answer += S.top();
        S.pop();
      }
      S.push(Infix[i]);
    }
  }

  while(!S.empty()) {
    Answer += S.top();
    S.pop();
  }

  cout << Answer << '\n';
  return 0;
}