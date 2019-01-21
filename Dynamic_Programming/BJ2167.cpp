#include <iostream>
using namespace std;

int arr[301][301];
int S[10001];
int N, M;
int K;
int i, j, x, y;
int sum;

int main() {
	scanf_s("%d%d", &N, &M);
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			scanf_s("%d", &arr[i][j]);
			
		}
	}

	scanf_s("%d", &K);

	for (int n = 0; n < K; n++) {
		scanf_s("%d%d%d%d", &i, &j, &x, &y);
		sum = 0;
		for (int a = i - 1; a <= x - 1; a++) {
			for (int b = j - 1; b <= y - 1; b++) {
			
				sum += arr[a][b];
				S[n] = sum;
				
			}
		}
	}
	for (int a = 0; a < K; a++) printf("%d\n", S[a]);
	return 0;
}