#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t, n, a, b;
	
	cin >> t;
	while (t--) {
		vector<pair<int, int > > v;
		int cnt = 1;

		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a >> b;
			v.push_back(make_pair(a, b));
		}
		sort(v.begin(), v.end());

		int tmp = v[0].second;
		for (int i = 1; i < n; i++) {
			if (tmp > v[i].second) {
				tmp = v[i].second;
				cnt++;
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}