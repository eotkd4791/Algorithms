#include <bits/stdc++.h>
using namespace std;

int N, M, arr[100001], psum[100001];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for(int i = 0; i < N; i++) {
    cin >> arr[i];
  }  

  for(int i = 1; i <= N; i++) {
    psum[i] = psum[i - 1] + arr[i - 1];
  }

  int from, to;
  for(int i = 0; i < M; i++) {
    cin >> from >> to;
    cout << psum[to] - psum[from - 1] << '\n';
  }
  return 0;
}