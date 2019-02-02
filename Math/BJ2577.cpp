#include <iostream>
using namespace std;

int A, B, C, mtp, dgt[10], cnt[10];
int main() {
	scanf("%d%d%d", &A, &B, &C);
	mtp = A * B*C;
	for (int i = 0; i < 10; i++) {
		dgt[i] = 0;
		dgt[i] = mtp % 10;
		mtp /= 10;
	}
	for (int i = 9; i > 0; i--) {
		if (dgt[i] == 0) dgt[i] = -1;
		if (dgt[i-1] != 0) break;
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if(dgt[i] == j) cnt[j]++;
		}
	}
	for (int i = 0; i < 10; i++) {
		printf("%d\n", cnt[i]);
	}
	return 0;
}