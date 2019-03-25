#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int a[10];
void recur(int *arr, bool *check, int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
		return;
	}
	
	for (int i = 0; i < N; i++) {
		if (!check[i]) {
			arr[cnt] = a[i];
			check[i] = 1;
			recur(arr, check, cnt + 1);
			check[i] = 0;
		}
	}
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}
	sort(a, a + N);
	int arr[10] = {};
	bool check[10] = {};
	recur(arr,check, 0);
	return 0;
}