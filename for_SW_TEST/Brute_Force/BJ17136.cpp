#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

const int MAX = 10;
int MIN = INT_MAX;
int field[MAX + 1][MAX + 1];
int paper[] = { 0,5,5,5,5,5 };
int cnt;

void recur(int x, int y) {
	if (y == MAX) 
		recur(x + 1, 0);
	
	if (x == MAX) {
		MIN = min(MIN, cnt);
		return;
	}
	if (field[x][y] == 0) {
		recur(x, y + 1);
		return;
	}

	for (int sz = 5; sz >= 1; sz--) {
		if (paper[sz] == 0 || x + sz > MAX || y + sz > MAX)
			continue;

		bool flag = 0;

		for (int i = 0; i < sz; i++) {
			for (int j = 0; j < sz; j++) {
				if (field[x + i][y + j] == 0) {
					flag = 1;
					break;
				}
			}
			if (flag)
				break;
		}
		if (flag)
			continue;

		for (int i = 0; i < sz; i++) 
			for (int j = 0; j < sz; j++) 
				field[x + i][y + j] = 0;
			
		paper[sz]--;
		cnt++;

		recur(x, y + sz);
		for (int i = 0; i < sz; i++) 
			for (int j = 0; j < sz; j++) 
				field[x + i][y + j] = 1;
			
		paper[sz]++;
		cnt--;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			cin >> field[i][j];

	recur(0, 0);
	if (MIN == INT_MAX)
		MIN = -1;
	cout << MIN;
	return 0;
}