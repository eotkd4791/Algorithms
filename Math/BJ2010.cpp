#include <iostream>
using namespace std;
int N,a,b,sum;

int main() {
	scanf("%d",&N);
	for (int i = 1; i < N; i++) {
		scanf("%d", &a);
		sum += a - 1;
	}
	scanf("%d", &b);
	sum += b;
	printf("%d\n", sum);
	return 0;
}