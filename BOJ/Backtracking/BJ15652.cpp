/*
=========================
BOJ15652 N과 M (4)
=========================

중복도 출력하는 방식
*/

#include <iostream>
using namespace std;

int N, M;
int arr[10];

void recur(int* arr, int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			printf("%d ", arr[i]+1);
		}
		printf("\n");
		return;
	}
	int st = 0;
	if(cnt!=0) st = arr[cnt-1];
	for (int i = st; i < N; i++) {
		arr[cnt] = i;
		recur(arr, cnt + 1);
	}
}

int main() {
	scanf("%d%d", &N, &M);
	int arr[M] = {};
	recur(1, 0);
	return 0;
}