#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int Materials[15001];
int Answer;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for(int i=0; i<N; i++) {
    cin >> Materials[i];
  }

  sort(Materials, Materials + N);
  
  int left = 0;
  int right = N - 1;

  while(left < right) {
    if(Materials[left] + Materials[right] < M) {
      left++;
    }
    else if(Materials[left] + Materials[right] == M) {
      Answer++;
      left++;
      right--;
    } 
    else {
      right--;
    }
  }
  
  cout << Answer << '\n';
  return 0;
}