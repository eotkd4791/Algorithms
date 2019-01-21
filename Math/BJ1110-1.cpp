#include <stdio.h>

int a, b, c;
int X, num;
int N;


int main(void) {

	scanf("%d", &num);


	X = num;


	do {
		a = X / 10;
		b = X % 10;
		c = a + b;
		X = b * 10 + c % 10;
		a = b;
		b = c % 10;
		N++;

	} while (X != num);


	printf("%d\n", N);


	return 0;
}
