
/////////////////////////////////////
/*
         BOJ16235 나무 재테크
                                   */
/////////////////////////////////////
/*
빡구현하는 시뮬레이션 문제였다.
4차원 배열을 만들면서 나이를 인덱스에
저장해놨는데, k값에 대한 for문이 돌면서
연산결과가 바뀌는 것을 인지하지 못했다.

봄에 죽는 나무, 나이 먹는 나무를 따로 
tmp배열에 저장해서 여름 때 대입해주는
식으로 풀었다.

봄 여름 가을 겨울이 차례대로 가기 때문에
처음 코드를 짤 때, 계절에 대한 변수를 
따로 만든 것은 상당히 무의미했다.

3차원 배열을 이용하여 [x][y][나이]=나무 갯수
로 풀었다.

구현력을 키울 수 있는 문제들을 많이 풀어봐야겠다.
*/
#include <iostream>
using namespace std;

int N, M, K;
int field[12][12][1020];
int A[12][12];
int tmp[12][12][1020];

bool OOB(int x, int y) {
	if (1 <= x && x <= N && N >= y && y >= 1) 
		return true;
	return false;
}

int main() {
	scanf("%d%d%d", &N, &M, &K);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &A[i][j]);
			field[i][j][0] = 5;
		}
	}
	int x, y, z = 0;
	for (int i = 1; i <= M; i++) {
		scanf("%d%d%d", &x, &y, &z);
		field[x][y][z]++;
	}
	while (K--) {
		//봄
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				for (int k = 1; k < 1020; k++) {
					if (field[i][j][k] != 0) {
						while (field[i][j][k] > 0) {
							if (field[i][j][0] >= k) {
								field[i][j][0] -= k;
								tmp[i][j][k + 1]++;
								field[i][j][k]--;
							}
							else {
								tmp[i][j][0] += (field[i][j][k] * (k / 2));
								field[i][j][k] = 0;
							}
						}
					}
				}
			}
		}
		//여름-죽은거 나이의 반 양분에 더하기
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				for (int k = 0; k < 1020; k++) {
					field[i][j][k] += tmp[i][j][k];
					tmp[i][j][k] = 0;
				}
			}
		}

		//가을
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				int k = 5;
				while (k < 1020) {
					int dx[8] = { 0,0,1,-1,1,1,-1 ,-1 };
					int dy[8] = { 1,-1,0,0,1,-1,-1, 1 };
					if (field[i][j][k] != 0) {
						for (int n = 0; n < 8; n++) {
							int nx = i + dx[n];
							int ny = j + dy[n];
							if (OOB(nx, ny)) field[nx][ny][1] += field[i][j][k];
						}
					}
					k += 5;
				}
			}
		}




		//겨울
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				field[i][j][0] += A[i][j];
			}
		}
	}

	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k < 1020; k++) {
				//if (field[i][j][k] != 0) 있으나 없으나 똑같다.
				cnt += field[i][j][k];
			}
		}
	}
	printf("%d\n", cnt);
	return 0;
}