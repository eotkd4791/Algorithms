#include <iostream>
#include <algorithm>
using namespace std;
int A, B, C;
int money;

int main() {
	scanf("%d%d%d", &A, &B, &C);
	if (A == B && B == C) {
		money = 10000 + (A * 1000);
	}
	if ((A == B&&C!=A) || (B == C && A!=B) || (C == A && B!=C)) {
		if (A == B) money = 1000 + (A * 100);
		else if (B == C) money = 1000 + (B * 100);
		else money = 1000 + (C * 100);
	}
	if (A != B && B != C && C != A) {
		money = max(A, max(B, C)) * 100;
	}
	printf("%d\n", money);
	return 0;
}