#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 1000001;
stack<int> S;
int N;
int A[MAX];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for(int i=0; i<N; i++) {
    cin >> A[i];
  }

  vector<int> Answer(N, -1);

  for(int i=0; i<N; i++) {
    while(!S.empty() && A[i] > A[S.top()]) {
      Answer[S.top()] = A[i];
      S.pop();
    }
    S.push(i);
  }
  for(const auto& element : Answer) {
    cout << element << ' ';
  }
  return 0;
}