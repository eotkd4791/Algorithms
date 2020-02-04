#include <iostream>
#include <algorithm>
#include <string>
#define endl '\n'
using namespace std;

int L, C;
char field[16];
bool check[16];
string str;

void recur(int idx, int cnt, int m, int z) {
	if (cnt == L) {
		if (m >= 1 && z >= 2) {
			cout << str << endl;
		}
		return;
	}
	for (int i = idx; i < C; i++) {
		if (check[i]) continue;
		check[i] = true;
		
		str.push_back(field[i]);
		int tmp1 = m, tmp2 = z;
		if (field[i] == 'a' || field[i] == 'e' || field[i] == 'i' || field[i] == 'o' || field[i] == 'u') {
			tmp1++;
		}
		else {
			tmp2++;
		}
		recur(i + 1, cnt + 1, tmp1, tmp2);
		check[i] = false;
		str.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> L >> C;
	for (int i = 0; i < C; i++) {
		cin >> field[i];
	}

	sort(field, field + C);
	recur(0, 0, 0, 0);
	return 0;
}