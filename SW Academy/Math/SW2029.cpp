#include <stdio.h>

int main() {
	int T;
	
	int a,b = 0;

	scanf("%d", &T);

	for (int i = 1; i <= T; i++) {
		
		scanf_s("%d%d", &a,&b);
		
		printf("#%d %d %d\n", i, a/b, a%b );
		

	}
	return 0;
}
