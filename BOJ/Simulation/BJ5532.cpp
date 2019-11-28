#include <iostream>
#include <algorithm>
using namespace std;

int L, A, B, C, D;
int a, b, l;

int main() {
	scanf("%d%d%d%d%d", &L, &A, &B, &C, &D);
	
	if (A % C != 0) 
		a = A / C + 1;
	else
		a = A / C;
	
	if (B % D != 0)
		b = B / D + 1;
	else
		b = B / D;
	
	l = L - max(a, b);
	
	printf("%d\n", l);
	return 0;
} 
