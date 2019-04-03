//////////////////////////
/*
    BOJ5543 상근날드
                        */
//////////////////////////

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int a, b, c, d, e;
	scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
	printf("%d", (min(a, min(b, c)) + min(d, e)) - 50);
	return 0;
}