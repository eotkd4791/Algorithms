#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	int T = 0;
	int N,K = 0;
	int score[100] = {};
	int Msum = 0;
	
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		scanf("%d%d", &N,&K);
		for (int j = 0; j < N; j++) {
			scanf("%d", &score[j]);
		}
		sort(score, score + 100);
		reverse(score, score + 100);
		for (int j = 0; j < K; j++) {
			Msum += score[j];
		}
		printf("#%d %d\n", i, Msum);
		Msum = 0;
		for (int j = 0; j < 100; j++) {
			score[j] = 0;
		}
	}
	return 0;
}