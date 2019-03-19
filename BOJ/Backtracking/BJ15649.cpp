#include <iostream>
using namespace std;

int n, m;

void func(int* arr, bool* isused, int k) {
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!isused[i]) {
			arr[k] = i;
			isused[i] = 1;
			func(arr, isused, k + 1);
			isused[i] = 0;
		}
	}
}


int main(void) {
	cin >> n >> m;
	bool isused[n] = {};
	int arr[m] = {};
	func(arr, isused, 0);
}