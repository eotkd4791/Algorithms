#include <iostream>

using namespace std;

int dp[50];
int check[50];

int count(int x) {

	if (x == 0) return 1;
	if (x == 1) return 1;
	if (x == 2) return 2;

	if (check[x] != 0)
		return dp[x];
	check[x] = 1;

	dp[x] = count(x - 3) + count(x - 2) + count(x - 1);
	return dp[x];
}

int main() {
	int T = 0;
	int n[10]= {};												//입력받은 값
	
	scanf_s("%d", &T);											//테스트 케이스 갯수

	for (int i = 0; i < T; i++) {
		scanf_s("%d", &n[i]);
	}

	for (int i = 0; i < T; i++) {
		printf("%d\n", count(n[i]));
	}

	return 0;
}  
