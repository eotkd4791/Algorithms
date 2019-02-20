/*정수 삼각형
합이 최대가 되는 경로에 있는 수의 합을 출력한다.
밑으로 내려가서 합이 최대가 되는 경로에 새로운 값을 더해주는 식으로 풀어나간다.*/
#include <iostream>
#include <algorithm>
using namespace std;

int n, dp[510][510], arr[510][510];

int tri(int i, int j) {
	if (i == n) return arr[i][j];
	int &ret = dp[i][j];
	if (ret != 0) return ret;
	ret = arr[i][j] + max(tri(i + 1, j), tri(i + 1, j + 1));
	return ret;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	printf("%d\n", tri(0, 0));
	return 0;
}
