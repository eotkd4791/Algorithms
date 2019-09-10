#include <iostream>
#include <algorithm>
using namespace std;

bool recur(string& wild, string& file, int w_idx, int f_idx) {
	if ((wild[w_idx] == file[f_idx] || wild[w_idx] == '?') && w_idx < wild.length() && f_idx < file.length()) 
		return recur(wild, file, w_idx + 1, f_idx + 1);
	if (w_idx == wild.length() && f_idx == file.length())
		return true;
	if (wild[w_idx] == '*') {
		for (int idx = f_idx; idx <= file.length(); idx++) {
			if (recur(wild, file, w_idx + 1, idx))
				return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int C, N;
	string wild, file;

	cin >> C;
	while (C--) {
		cin >> wild;
		cin >> N;

		string ans[101];
		int idx = 0;

		for (int n = 0; n < N; n++) {
			cin >> file;
			if (recur(wild, file, 0, 0)) 
				ans[idx++] = file;
		}
		sort(ans, ans + idx);
		for (int i = 0; i < idx; i++) 
			cout << ans[i] << '\n';
	}
	return 0;
}