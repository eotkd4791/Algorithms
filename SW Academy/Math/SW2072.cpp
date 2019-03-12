#include <stdio.h>

int main() {
	int T;//테스트케이스의 개수
	int arr[10] = {};
	int sum = 0; //가상의 정답

	scanf("%d", &T);

	for (int i = 1; i <= T; i++) {
		for (int j = 0; j < 10; j++) {

			scanf("%d", &arr[j]);

			if (arr[j] % 2 == 1)
				sum = sum + arr[j];

		}


		printf("#%d %d\n", i, sum);
		sum = 0;
	}
	return 0;
}

