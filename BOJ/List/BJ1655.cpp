#include <iostream>
#include <queue>
#include <functional>
using namespace std;

int N, a;
priority_queue<int, vector<int>, greater<int> > MinPq;
priority_queue<int> MaxPq;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  for(int i = 0; i < N; i++) {
    cin >> a;
    if(MaxPq.empty()) {
      MaxPq.push(a);
    } else {
      if(MaxPq.size() == MinPq.size()) {
        MaxPq.push(a);
      } 
      else if(MaxPq.size() > MinPq.size()) {
        MinPq.push(a);
      }
      if(MaxPq.top() > MinPq.top()) {
        int MaxTop = MaxPq.top();
        int MinTop = MinPq.top();
        MaxPq.pop();
        MinPq.pop();
        MaxPq.push(MinTop);
        MinPq.push(MaxTop);
      }
    }
    cout << MaxPq.top() << '\n';
  }
  return 0;
}