/*점화식 찾는 과정이 너무 어려웠고, 더 많은 연습이 필요하다고 생각한다.*/

#include <iostream>
using namespace std;

int dp[1001];
int check[1001];

int tile_cnt(int n) {
	if (n == 1) return 1;
	if (n == 2) return 3;
	if (check[n] != 0) 
		return dp[n];
	check[n] = 1;
	dp[n] = ((tile_cnt(n - 1))%10007 + (2 * tile_cnt(n - 2))%10007)%10007; //나머지 출력시
	return dp[n];
}

int main() {
	int N = 0;
	scanf("%d", &N);
	printf("%d\n", tile_cnt(N)%10007);
	return 0;
}
