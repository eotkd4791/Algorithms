#include <iostream>
using namespace std;

int N, M;

void recur(int *arr, int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			printf("%d ", arr[i] + 1);
		}
		printf("\n");
		return;
	}
	for (int i = 0; i < N; i++) {
			arr[cnt] = i;
			recur(arr, cnt + 1);
	}
}

int main() {
	scanf("%d%d", &N, &M);
	int arr[10] = {};
	recur(arr, 0);
	return 0;
}
 
