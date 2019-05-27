////////////////////////////////
/*
         BOJ11399 ATM
                              */
////////////////////////////////

#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[1001];
int MIN;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			MIN += arr[j];
		}
	}
	cout << MIN;
	return 0;
}