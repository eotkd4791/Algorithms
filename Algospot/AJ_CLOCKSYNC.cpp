#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <cstring>
using namespace std;

vector<vector<int> > v({
	vector<int>({ 0, 1, 2 }),
	vector<int>({ 3, 7, 9, 11 }),
	vector<int>({ 4, 10, 14, 15 }),
	vector<int>({ 0, 4, 5, 6, 7 }),
	vector<int>({ 6, 7, 8, 10, 12 }),
	vector<int>({ 0, 2, 14, 15 }),
	vector<int>({ 3, 14, 15 }),
	vector<int>({ 4, 5, 7, 14, 15 }),
	vector<int>({ 1, 2, 3, 4, 5 }),
	vector<int>({ 3, 4, 5, 9, 13 })
});

int field[16];
int check[16];
int MIN=INT_MAX;

void dfs(int swit, int cnt) {
	if (MIN <= cnt) return;
	for (int i = 0; i < 16; i++) {
		if (check[i] % 4 != 0) break;
		else if (check[i] % 4 == 0 && i < 15) continue;
		else if (check[i] % 4 == 0 && i == 15) {
			MIN = min(MIN, cnt);
			return;
		}
	}
	if (swit > 9) return;
	for (int i = 0; i < 4; i++) {
		int sz = v[swit].size();

		for (int j = 0; j < sz; j++) {
			check[v[swit][j]] += i;
		}
		dfs(swit + 1, cnt + i);
		for (int j = 0; j < sz; j++) {
			check[v[swit][j]] -= i;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int C;
	cin >> C;
	while (C--) {
		MIN = INT_MAX;
		memset(check, 0, sizeof(check));

		for (int i = 0; i < 16; i++) {
			cin >> field[i];
			if (field[i] == 12)		check[i] = 0;
			else if (field[i] == 9) check[i] = 3;
			else if (field[i] == 6) check[i] = 2;
			else if (field[i] == 3) check[i] = 1;
		}

		if (field[8] != field[12])
			cout << "-1" << '\n';
		else if (field[14] != field[15])
			cout << "-1" << '\n';
		else {
			dfs(0, 0);
			if (MIN == INT_MAX)
				MIN = -1;
			cout << MIN << '\n';
		}
	}
	return 0;
} 
