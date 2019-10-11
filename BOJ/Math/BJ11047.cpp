#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, k;
	int arr[10] = {};

	cin >> n >> k;
	for (int i = 0; i < n; i++) 
		cin >> arr[i];

	sort(arr, arr + n);
	
	int idx = n - 1;
	int cnt = 0;
	while (k > 0) {
		if (arr[idx] > k)
			idx--;
		else {
			cnt += k / arr[idx];
			k %= arr[idx];
		}
	}
	cout << cnt;
	return 0;
}