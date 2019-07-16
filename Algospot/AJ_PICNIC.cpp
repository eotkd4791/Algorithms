#include <iostream>
#include <utility>
using namespace std;

int C, n, m;
int cnt;
pair<int, int> arr[45];
bool check[11];

void recur(int idx, int gnum) {
	if (m == 0) return;
	if (gnum == n / 2) {
		cnt++;
		return;
	}

	for (int i = idx; i < n; i++) {
		if (check[i]) continue;
		check[i] = 1;
		for (int j = i; j < m; j++) {
			if (i == arr[j].first && !check[arr[j].second]) {
				check[arr[j].second] = 1;
				recur(i + 1, gnum + 1);
				check[arr[j].second] = 0;
			}
		}
		check[i] = 0;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> C;
	for (int c = 1; c <= C; c++) {
		cin >> n >> m;
		for (int i = 0; i < m; i++)
			cin >> arr[i].first >> arr[i].second;
		recur(0, 0);
		cout << cnt << '\n';
		cnt = 0;
	}
	return 0;
}