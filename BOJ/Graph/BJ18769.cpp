#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int T;
int R,C;
vector<int> parent;
vector<int> height;
int answer;
vector<pair<int, pair<int, int> > > network;

void init() {
  network.clear();
  answer = 0;
  parent.resize((R * C) + 1);
  height.resize((R * C) + 1);
  for(int i = 1; i <= R * C; i++) {
    parent[i] = i;
    height[i] = 1;
  }
}

int find(int node) {
  if(parent[node] == node) {
    return node;
  }
  return parent[node] = find(parent[node]);
}

void merge(int a, int b) {
  int ra = find(a);
  int rb = find(b);

  if (height[ra] > height[rb]) {
		parent[rb] = ra;
	}
	else if(height[ra] < height[rb]) {
		parent[ra] = rb;
	}
	else {
		parent[ra] = rb;
		height[rb] = ++height[ra];
	}
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;
  while(T--) {
    cin >> R >> C;

    init();

    int node=1;
    int weight = 0;
    for(int i=0; i<R; i++) {
      for(int j=0; j<C-1; j++) {
        cin >> weight;
        network.push_back(make_pair(weight, make_pair(node, node + 1)));
        node++;
      }
      node++;
    }

    node = 1;
    for(int i=0; i<R-1; i++) {
      for(int j=0; j<C; j++) {
        cin >> weight; 
        network.push_back(make_pair(weight, make_pair(node, node + C)));
        node++;
      }
    }

    sort(network.begin(), network.end());
  
    for(int i=0; i<network.size(); i++) {
      int start = network[i].second.first;
      int end = network[i].second.second;
      int weight = network[i].first;

      if(find(start) != find(end)) {
        merge(start, end);
        answer += weight;
      }
    }
    cout << answer << '\n';
  }
  return 0;
}