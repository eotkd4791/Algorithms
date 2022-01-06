#include <iostream>
#include <algorithm>
using namespace std;

int N, M, K, Answer;
int Nums[10001];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M >> K;
  for(int i=0; i<N; i++) {
    cin >> Nums[i];
  }

  sort(Nums, Nums + N);
  int First = Nums[N-1];
  int Second = Nums[N-2];

  int Count = (M / (K + 1)) * K + (M % (K + 1));
  Answer = (First * Count) + (Second * (M - Count));

  cout << Answer << '\n';
  return 0;
}