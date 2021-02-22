#include <iostream>
#define ll long long
#define MAX 100000
using namespace std;

int N;
ll dist[MAX+1];
ll cost[MAX+1];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for(int i=0; i<N-1; i++) {
    cin >> dist[i];  
  }
  for(int i=0; i<N; i++) {
    cin >> cost[i];
  }

  ll ans = 0;
  for(int i=0; i<N-1; i++) {
    if(cost[i] < cost[i+1]) {
      cost[i+1] = cost[i];
    }
    ans += (cost[i] * dist[i]);
  }
  
  cout << ans;
  return 0;
}