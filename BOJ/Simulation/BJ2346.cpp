#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int n;
vector<pair<int, int> > paper;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i=1; i<=n; i++) {
    int a;
    cin >> a;
    paper.push_back(make_pair(i, a));
  }

  int current = 0;
  int cnt = n;
  for (int i=0; i<n; i++) {
    cout << paper[current].first << ' ';
    int dist = paper[current].second;
    paper.erase(paper.begin() + current);

    if(dist > 0) {
      dist--;
    }
    cnt--;
    if(cnt == 0) {
      break;
    }
    current += dist;
    if(current < 0) {
      current = cnt + current % cnt;
    }
    current %= cnt;
  }
  return 0;
}