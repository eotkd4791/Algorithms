#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N, arr[301], dp[301];

int recur(int idx) {
	if (idx == 1)
		return arr[idx];
	if (idx == 2)
		return arr[idx-1] + arr[idx];

	int& ret = dp[idx];
	if (ret != -1)
		return ret;
	else {
		ret = 0;
		return ret = max(recur(idx - 3) + arr[idx - 1] + arr[idx], recur(idx - 2) + arr[idx]);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) 
		cin >> arr[i];
	memset(dp, -1, sizeof(dp));
	cout << recur(N);
	return 0;
}