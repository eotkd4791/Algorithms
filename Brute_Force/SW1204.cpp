#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int T = 0;
	int Tnum = 0;
	int cnt = 0;
	int score[1000] = {};
	int same[1000] = {};
	int target = 0;
	int MAX = 0;

	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		scanf("%d", &Tnum);
		for (int j = 0; j < 1000; j++) {
			scanf("%d", &score[j]);
		}
		sort(score, score + 1000);
		for (int j = 0; j < 1000; j++) {
			if (score[j] == score[j + 1]) {
				cnt++;
				same[j] = cnt;
			}
			else cnt = 0;
		}
		for (int i = 0; i < 1000; i++) {
			MAX = max(MAX,max(same[i], same[i + 1]));
		}
		for (int i = 0; i < 1000; i++) {
			if (same[i] == MAX) target = score[i];
		}
		printf("#%d %d\n", i,target);
		for (int i = 0; i < 1000; i++) {//모든 값 초기화
			score[i] = 0;
			same[i] = 0;
		}
		target = 0;
		MAX = 0;
	}
	return 0;
}