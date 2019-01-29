#include <iostream>
using namespace std;

int rcs(int n) {
	if (n == 0) return 1;
	if (n == 1) return 3;
	return rcs(n - 1) + (3*n*(n+1))/2;
}
int main() {
	int N = 0;
	scanf("%d", &N);
	printf("%d\n", rcs(N));
}