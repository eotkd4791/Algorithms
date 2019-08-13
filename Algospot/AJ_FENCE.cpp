#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dc(vector<int>& v, int left, int right) {
	if (left == right)
		return v[left];

	int mid = (left + right) / 2;
	int ret = max(dc(v, left, mid), dc(v, mid + 1, right));

	int l = mid;
	int r = mid + 1;
	int height = min(v[l], v[r]);

	ret = max(ret, height * 2);

	while (left < l || r < right) {
		if (r < right && (l == left || v[l - 1] < v[r + 1])) {
			r++;
			height = min(height, v[r]);
		}
		else {
			l--;
			height = min(height, v[l]);
		}
		ret = max(ret, height * (r - l + 1));
	}
	return ret;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int C; int N; int var;
	cin >> C;
	while (C--) {
		vector<int> v;

		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> var;
			v.push_back(var);
		}
		int ans = dc(v, 0, N-1);
		cout << ans << "\n";
	}
	return 0;
}