#include <stdio.h>

int main() {
	int T;
	int arr[10] = {};
	int MAX = 0;

	scanf("%d", &T);

	for (int i = 1; i <= T; i++) {

		for (int j = 0; j < 10; j++) {

			scanf("%d", &arr[j]);

			if (MAX <= arr[j])
				MAX = arr[j];
		}

		printf("#%d %d\n", i, MAX);
		MAX = 0;

	}
	return 0;
}
