////////////////////////
/*
   BOJ4504 배수 찾기
                      */
////////////////////////
#include <iostream>

using namespace std;

int main() {
	int n = 0;
	int mtp[1001] = { 1 };


	scanf("%d", &n);					


	for (int i = 0; i < 1001; i++) {
		scanf("%d", &mtp[i]);
		if (mtp[i] == 0) break;
	}

	
	for (int j = 0; j < 1001; j++) {
		if (mtp[j] == 0) break;

		if (mtp[j] % n == 0)
			printf("%d is a multiple of %d.\n", mtp[j], n);
		else
			printf("%d is NOT a multiple of %d.\n", mtp[j], n);
	}
	
	return 0;
}
