#include <stdio.h>

int arr[5];

int main() 
{
		int result = 0;

		for (int i = 0; i < 5; i++) {
			scanf("%d", &arr[i]);
		}
		for (int i = 0; i < 5; i++) {
			if (arr[i] <= 40)
				arr[i] = 40;
			result += arr[i];
		}
		printf("%d\n", result / 5);
	
	return 0;
}
 
