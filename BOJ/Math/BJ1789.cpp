///////////////////////////
/*
	BOJ1789 수들의 합
                        */
//////////////////////////

#include <iostream>
using namespace std;

long long S;

int main() {
	scanf("%lld", &S);

	long long i = 1;
	while (1) {
		if ((i*(i + 1)) / 2 > S) {
			printf("%lld\n", i-1);
			break;
		}
		if ((i*(i + 1)) / 2 == S) {
			printf("%lld\n", i);
			break;
		}
		i++;
	}
	return 0;
}