#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int n;
int arr[100001];
stack<int> s;
vector<char> v;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i=0; i<n; i++) {
    cin >> arr[i];
  }

  s.push(1);
  v.push_back('+');

  int num=2;
  int index=0;
  while(v.size() != n * 2) {
    if(!s.empty() && arr[index] == s.top()) {
      s.pop();
      v.push_back('-');
      index++;
    }
    else {
      s.push(num++);
      v.push_back('+');
    }
  }

  if(v.size() == n * 2 && v.back() == '-') {
    for(int i=0; i<v.size(); i++) {
      cout << v[i] << '\n';
    }
  }

  else { 
    cout << "NO" << '\n';
  }
  return 0;
}