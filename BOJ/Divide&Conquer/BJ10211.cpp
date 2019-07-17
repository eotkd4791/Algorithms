#include <iostream>
#include <algorithm>
using namespace std;

int n;
int x[1002];

int MaxCrossSubArr(int low, int mid, int high) {
	int Lsum = -987654321;
	int sum = 0;
	for (int i = mid; i >= low; i--) {
		sum += x[i];
		if (sum > Lsum) 
			Lsum = sum;
	}

	int Rsum = -987654321;
	sum = 0;
	for (int j = mid + 1; j <= high; j++) {
		sum += x[j];
		if (sum > Rsum)
			Rsum = sum;
	}
	return Lsum + Rsum;
}

int MaxSubArr(int low, int high) {
	if (low == high)
		return x[low];
	int mid = (low + high) / 2;
	int Ls = MaxSubArr(low, mid);
	int Rs = MaxSubArr(mid + 1, high);
	int Cs = MaxCrossSubArr(low, mid, high);
	return max(max(Rs, Cs), Ls);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> n;
		for (int i = 0; i < n; i++) 
			cin >> x[i];

		cout << MaxSubArr(0, n - 1) << '\n';
	}
	return 0;
}