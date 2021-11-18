#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

const int MAX = 1000001;
stack<int> S;
int N;
int A[MAX];
int Answer[MAX];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for(int i=0; i<N; i++) {
    cin >> A[i];
  }

  memset(Answer, -1, sizeof(Answer));

  for(int i=0; i<N; i++) {
    while(!S.empty() && A[i] > A[S.top()]) {
      Answer[S.top()] = A[i];
      S.pop();
    }
    S.push(i);
  }
  for(int i=0; i<N; i++) {
    cout << Answer[i] << ' ';
  }
  return 0;
}