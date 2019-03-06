#include <iostream>
#include <cstring>
using namespace std;

int arr[4][8]; //톱니바퀴[번호][이빨]
int k; //회전수
int turn[4];   //각 톱니바퀴별 회전방향을 저장하는 배열
int num, dir; //톱니바퀴 번호, 회전방향

int main() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
	scanf("%d", &k);
	while (k--) {
		scanf("%d%d", &num, &dir);
		num -= 1; // 배열의 인덱스=톱니바퀴 번호 -1
		turn[num] = dir; //톱니바퀴 번호 -1 을 인덱스로 사용, 방향dir 저장
		for (int i = num - 1; i >= 0; i--) {//입력받은 톱니바퀴의 왼쪽에 있는 톱니바퀴
			if (arr[i][2] != arr[i + 1][6]) {
				turn[i] = -turn[i + 1];
			}
			else break;//맞닿은 극이 같아서 돌지 않을 때
		}
		for (int i = num + 1; i < 4; i++) {//입력받은 톱니의 오른쪽에 있는 톱니바퀴
			if (arr[i][6] != arr[i - 1][2]) {
				turn[i] = -turn[i - 1];
			}
			else break;// 한 톱니가 회전하지 않으면 오른쪽에 있는 톱니도 회전하지 않는다.
		}
		for (int n = 0; n < 4; n++) {
			if (turn[n] == 0) continue;//멈춰있는 톱니바퀴는 회전시키지 않고 지나간다.
			if (turn[n] == 1) {
				int tmp = arr[n][7];
				for (int m = 7; m >= 1; m--) {
					arr[n][m] = arr[n][m - 1];
				}//1까지만 돌리고 tmp에 저장해 놨던 값을 대입.
				arr[n][0] = tmp;
			}
			else if (turn[n] == -1) {
				int tmp = arr[n][0];
				for (int m = 0; m < 7; m++) {
					arr[n][m] = arr[n][m + 1];
				}
				arr[n][7] = tmp;
			}
		}
		memset(turn, 0, sizeof(turn));
	}
	int result = 0;
	int sum = 1;
	for (int i = 0; i < 4; i++) {
		if (arr[i][0] == 1) result += sum;
		sum *= 2;
	}
	printf("%d\n", result);
	return 0;
}
