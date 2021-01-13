#include <iostream>
using namespace std;

int N;
int weight[55];
int height[55];
int rate[55];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  for(int i=0; i<N; i++) {
    cin >> weight[i] >> height[i];
  }

  for(int i=0; i<N; i++) {
    for(int j=0; j<N; j++) {
      if(i==j) rate[i]++;
      else if(weight[i] < weight[j] && height[i] < height[j]) {
        rate[i]++;
      }
    }
  }
  for(int i=0; i<N; i++) {
    cout << rate[i] << ' ';
  }
}