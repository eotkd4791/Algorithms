#include <stdio.h>

int a, b, c;
int X, num;
int N;


int main(void) {

	scanf("%d", &num);

	X = num;

	while (1) {

		a = X / 10;
		b = X % 10;
		c = a + b;
		X = b * 10 + c % 10;
		if (X == num) break;
		else {
			a = b;
			b = c % 10;
			N++;
		}

	}

	printf("%d\n", N + 1);

	return 0;
}