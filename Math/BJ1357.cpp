#include <iostream>
using namespace std;

int result;

int Rev(int n) {
	if (n < 10) return n;
	result = 0;
	while (1) {
		result *= 10;
		result += n % 10;
		if (n < 10) break;
		n /= 10;
	}
	return result;
}

int main() {
	int X, Y = 0;
	scanf("%d%d", &X, &Y);
	printf("%d\n", Rev(Rev(X) + Rev(Y)));
}