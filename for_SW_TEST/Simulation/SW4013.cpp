#include <iostream>
#include <cstring>
using namespace std;

int T, K, idx ,rtt;
int arr[4][8];
int dir[4];

int main() {
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d", &K);
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 8; j++) {
				scanf("%d", &arr[i][j]);
			}
		}
		
		while (K--) {
			scanf("%d%d", &idx, &rtt);
			idx -= 1;
			dir[idx] = rtt;
			//left
			for (int i = idx - 1; i >= 0; i--) {
				if (arr[i][2] != arr[i + 1][6]) {
					dir[i] = -dir[i + 1];
				}
				else break;
			}
			//right
			for (int j = idx + 1; j < 4; j++) {
				if (arr[j - 1][2] != arr[j][6]) {
					dir[j] = -dir[j - 1];
				}
				else break;
			}
			for (int n = 0; n < 4; n++) {
				if (dir[n] == 0) continue;
				if (dir[n] == 1) {//시계 
					int tmp = arr[n][7];
					for (int m = 7; m >=1; m--) { //도는 방향과 반대로 for문을 돌려야 값을 보존할 수 있다.
						arr[n][m] = arr[n][m-1];
					}
					arr[n][0] = tmp;
				}
				if (dir[n] == -1) {//반시계
					int tmp = arr[n][0];
					for (int m = 0; m <7; m++) {
						arr[n][m] = arr[n][m+1];
					}
					arr[n][7] = tmp;
				}
			}
			memset(dir, 0, sizeof(dir));
		}
		int result = 0;
		int sum = 1;
		for (int i = 0; i < 4; i++) {
			if (arr[i][0] == 1) result += sum;
			sum *= 2;
		}
		printf("#%d %d\n", t, result);
	}
	return 0;
}