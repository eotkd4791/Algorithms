////////////////////////////////
//============================//
//     BOJ15650 N과M (2)      //
//============================//
////////////////////////////////
////////////////////////////////
////////////////////////////////
//////////////////////////////////
/* 비내림차순을 위해서 arr[cnt-1]로
시작하는 포문을 돌려야하고, 중복을
피하기 위한 check를 사용해야한다. */
/////////////////////////////////


#include <iostream>
using namespace std;

int N, M;

void recur(int *arr, bool *check, int cnt) {
	if (cnt == M) {
		
		for (int i = 0; i < M; i++) {
			printf("%d ", arr[i]+1);
		}
		printf("\n");
		return;
	}
	int st = 0;
	if (cnt != 0) st = arr[cnt - 1];
	for (int i = st; i < N; i++) {
		if (!check[i]) {
			arr[cnt] = i;
			check[i] = 1;
			recur(arr, check, cnt + 1);
			check[i] = 0;
		}
	}
}


int main() {
	scanf("%d%d", &N, &M);
	int arr[10] = {};
	bool check[10] = {};
	recur(arr, check, 0);
	return 0;
}