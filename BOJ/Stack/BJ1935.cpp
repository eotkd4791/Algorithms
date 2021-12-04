#include <iostream>
#include <stack>
using namespace std;

int N;
double Numbers[26];
string Postfix;
stack<double> Stack;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cout << fixed;
  cout.precision(2);

  cin >> N >> Postfix;
  for(int i=0; i<N; i++) {
    cin >> Numbers[i];
  }

  for(const auto& P : Postfix) {
    if(P == '+' || P == '-' || P == '*' || P == '/') {
      double B = Stack.top();
      Stack.pop();
      double A = Stack.top();
      Stack.pop();
      
      switch(P) {
        case '+': Stack.push(A + B); break;
        case '-': Stack.push(A - B); break;
        case '*': Stack.push(A * B); break;
        case '/': Stack.push(A / B); break;
      }
    }
    else {
      Stack.push(Numbers[P - 65]);
    }
  }
  
  cout << Stack.top() << '\n';
  return 0;
}