#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int info[55][10] = {};
	vector<int> p = { 1,2,3,4,5,6,7,8 };

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> info[i][j];
		}
	}

	int MAX = 0;
	do {
		int arr[9] = {};
		for (int i = 0; i < 3; i++) 
			arr[i] = p[i];
		for (int i = 3; i < 8; i++) {
			arr[i+1] = p[i];
		}

		int idx = 0;		int ocnt = 0;
		int round = 0;		int sum = 0;
		int base[3] = {};	int ply = arr[idx];

		while (round < n) {
			int tmp = info[round][ply];
			if (tmp == 0) {
				ocnt++;
				if (ocnt == 3) {
					for (int i = 0; i < 3; i++)
						base[i] = 0;
					round++;
					ocnt = 0;
				}
			}

			else if (tmp == 1) {
				if (base[2]) 
					sum++;

				base[2] = base[1];
				base[1] = base[0];
				base[0] = 1;
			}
			else if (tmp == 2) {
				for (int i = 2; i >= 1; i--) 
					sum += base[i];
					
				base[2] = base[0]; 
				base[0] = 0;
				base[1] = 1;
			}
			else if (tmp == 3) {
				for (int i = 2; i >= 0; i--) {
					sum += base[i];
					base[i] = 0;
				}
				base[2] = 1;
			}
			else if (tmp == 4) {
				for (int i = 2; i >= 0; i--) {
					sum += base[i];
					base[i] = 0;
				}
				sum++;
			}

			idx++;
			if (idx == 9)
				idx = 0;
			
			ply = arr[idx];
			MAX = max(MAX, sum);
		}
	} while (next_permutation(p.begin(), p.end()));

	cout << MAX;
	return 0;
}