#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, x;
	int arr[10001] = {};
	cin >> n >> x;
	for (int i = 0; i < n; i++){
		cin >> arr[i];
		if (arr[i] < x)
			cout << arr[i] << " ";
    }
	return 0;
}
