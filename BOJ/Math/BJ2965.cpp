#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int a, b, c = 0;
	int cnt = 0;
	scanf("%d%d%d", &a, &b, &c);
	cnt = max((b - a - 1), (c - b - 1));
	printf("%d\n", cnt);
	return 0;
}