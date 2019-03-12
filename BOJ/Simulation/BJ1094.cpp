#include <iostream>
using namespace std;

int X;
int cnt;

int main() {
	scanf("%d", &X);
	while (X>0) {
		if (X % 2 == 1) cnt++;
		X /= 2;
	}
	printf("%d\n",cnt);
	return 0;
}