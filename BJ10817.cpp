#include <stdio.h>

int a, b, c;

int main() {

	scanf_s("%d %d %d", &a, &b, &c);
	if (a > b) {

		if (a > c) {

			if (b > c) printf("%d", b);

			else printf("%d", c);
		}

		else printf("%d", a);
	}

	else {								

		if (b > c) {
			
			if (a > c) printf("%d", a);

			else printf("%d", c);
		}

		else printf("%d", b);

	}

	

return 0;
}

