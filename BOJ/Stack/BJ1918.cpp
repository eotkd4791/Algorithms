#include <iostream>
#include <stack>
using namespace std;

string Input;
string Answer;
stack<char> S;

int Priority(char letter) {
  if(letter == '+' || letter == '-') {
    return 0;
  }
  if(letter == '*' || letter == '/') {
    return 1;
  }
  return 2;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> Input;
  for(const auto& letter : Input) {
    if('A' <= letter && letter <= 'Z') {
      Answer += letter;
    }
    else if(letter == '(') {
      S.push(letter);
    }
    else if(letter == ')') {
      while(!S.empty() && S.top() != '(') {
        Answer += S.top();
        S.pop();
      }
      S.pop();
    }
    else {
      while(!S.empty() && S.top() != '(' && Priority(S.top()) >= Priority(letter)) {
        Answer += S.top();
        S.pop();
      }
      S.push(letter);
    }
  }
  while(!S.empty()) {
    Answer += S.top();
    S.pop();
  }
  cout << Answer << '\n';
  return 0;
}