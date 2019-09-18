#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int C;
int dp[10001];
int arr[10001];
string str;

int func(int idx, int cnt) {
	int num[7] = { 1,1,1,1,1,1,1 };
	int stdd1 = arr[idx]; int stdd2 = arr[idx];
	int stdd3 = arr[idx]; int cmp = arr[idx + 1];

	for (int i = idx + 1; i < idx + cnt; i++) {
		if (arr[idx] == arr[i]) {//1
			num[1]++;
			if (num[1] == cnt)
				return 1;
		}
		
		if (stdd1 + 1 == arr[i] && num[3] == 1) {//2-1
			num[2]++;
			stdd1++;
			if (num[2] == cnt)
				return 2;
		}

		if (stdd2 - 1 == arr[i] && num[2]==1) {//2-2
			num[3]++;
			stdd2--;
			if (num[3] == cnt)
				return 2;
		}

		if (stdd3 != arr[i] && cmp == arr[i]) {//두 숫자 번갈아
			num[4]++;
			swap(stdd3, cmp);
			if (num[4] == cnt)
				return 4;
		}

		int diff = arr[idx + 1] - arr[idx];
		if (arr[idx] != arr[idx + 1] && diff == arr[i] - arr[i-1]) {//등차
			num[5]++;
			if (num[5] == cnt)
				return 5;
		}
	}
	return 10;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> C;
	while (C--) {
		cin >> str;

		int range = str.size();
		for (int i = 0; i < range; i++) 
			arr[i] = str[i] - '0';
	
		dp[0] = dp[1] = 0;
		dp[2] = func(0, 3);
		dp[3] = func(0, 4);
		dp[4] = func(0, 5);
		dp[5] = dp[2] + func(3, 3);
		dp[6] = min(dp[3] + func(4, 3), dp[2] + func(3, 4));
		
		for (int i = 7; i < range; i++) 
			dp[i] = min(min(dp[i - 3] + func(i - 3 + 1, 3), dp[i - 4] + func(i - 4 + 1, 4)), dp[i - 5] + func(i - 5 + 1, 5));
		
		cout << dp[range - 1] << '\n';
	}
	return 0;
}