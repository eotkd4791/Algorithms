#include <iostream>
#include <stack>
using namespace std;

int K;
int a;
int sum;
stack<int> s;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> K; 
  for(int i=0; i<K; i++) {
    cin >> a;
    
    if(a == 0) s.pop();
    else s.push(a);  
  }

  while(!s.empty()) {
    sum += s.top();
    s.pop();
  }
  cout << sum << '\n';
  return 0;
}