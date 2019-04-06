/////////////////////////////////////////
/*
          BOJ14500 테트로미노
                                       */
/////////////////////////////////////////

/*
빡구현을 하였다.
DFS를 떠올리지 못해서 아쉽고 부끄럽다.
다음부터 잘하자.
*/
#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int field[505][505];
int MAX;
int tmp,tmp1,tmp2, tmp3, tmp4, tmp5, tmp6, tmp7, tmp8;
int Mtmp;

bool OOB(int x, int y) {
	if (N > x && x >= 0 && 0 <= y && y < M) 
		return true;
	return false;
}

int dlfwk(int x, int y) {
	tmp1=0,tmp2 = 0;
	if (OOB(x + 3, y)) { // ㅣ모양
		
		for (int i = 0; i < 4; i++) {
			tmp1 += field[x + i][y];
		}
	}
	if (OOB(x, y + 3)) {// ㅡ
		
		for (int i = 0; i < 4; i++) {
			tmp2 += field[x][y+i];
		}
	}
	return max(tmp1, tmp2);
}
int ahwk(int x, int y) {// ㅏ ㅓ ㅗ ㅜ
	tmp1=0, tmp2=0, tmp3=0, tmp4 = 0;
	if (OOB(x + 2, y) && OOB(x + 1, y + 1)) {
		tmp1 = field[x][y] + field[x + 1][y] + field[x + 1][y + 1] + field[x + 2][y];
	}
	if (OOB(x + 2, y) && OOB(x + 1, y - 1)) {
		tmp2 = field[x][y] + field[x + 1][y] + field[x + 1][y -1] + field[x + 2][y];
	}
	if (OOB(x + 1, y - 1) && OOB(x + 1, y + 1)) {
		tmp3 = field[x][y] + field[x + 1][y] + field[x + 1][y - 1] + field[x + 1][y + 1];
	}
	if (OOB(x + 1, y + 1) && OOB(x, y + 2)) {
		tmp4= field[x][y] + field[x][y+1] + field[x + 1][y + 1] + field[x][y + 2];
	}
	Mtmp = max(max(max(tmp1, tmp2), tmp3), tmp4);
	return Mtmp;
}
int spah(int x, int y) {//ㅁ
	tmp = 0;
	if (OOB(x + 1, y + 1)) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				tmp += field[x+i][y+j];
			}
		}
	}
	return tmp;
}
int rldurwk(int x, int y) {
	tmp1 = 0, tmp2 = 0, tmp3 = 0, tmp4 = 0, tmp5 = 0, tmp6 = 0, tmp7 = 0, tmp8 = 0;
	if (OOB(x + 2, y + 1)) {
		tmp1 = field[x][y] + field[x + 1][y] + field[x + 2][y] + field[x + 2][y + 1];
	}
	if (OOB(x + 2, y - 1)) {
		tmp2 = field[x][y] + field[x + 1][y] + field[x + 2][y] + field[x + 2][y - 1];
	}
	if (OOB(x + 2, y) && OOB(x,y+1)) {
		tmp3 = field[x][y] + field[x][y + 1] + field[x + 1][y] + field[x + 2][y];
	}
	if (OOB(x+2, y + 1)) {
		tmp4 = field[x][y] + field[x][y + 1] + field[x + 1][y + 1] + field[x + 2][y + 1];
	}
	if (OOB(x + 1, y) && OOB(x, y + 2)) {
		tmp5 = field[x][y] + field[x][y + 1] + field[x][y + 2] + field[x + 1][y];
	}
	if (OOB(x + 1, y + 2)) {
		tmp6 = field[x][y] + field[x][y + 1] + field[x][y + 2] + field[x + 1][y + 2];
	}
	if (OOB(x + 1, y + 2)) {
		tmp7 = field[x][y] + field[x + 1][y] + field[x + 1][y + 1] + field[x + 1][y + 2];
	}
	if (OOB(x + 1, y - 2)) {
		tmp8 = field[x][y] + field[x + 1][y] + field[x + 1][y - 1] + field[x + 1][y - 2];
	}
	Mtmp = max(max(max(max(max(max(max(tmp1, tmp2), tmp3), tmp4), tmp5), tmp6), tmp7), tmp8);
	return Mtmp;
}

int wpxm(int x, int y) {
	tmp1 = 0, tmp2 = 0, tmp3 = 0, tmp4 = 0;
	//좌상 좌상회전 우상 우상회전
	if (OOB(x + 2, y + 1)) {
		tmp1 = field[x][y] + field[x + 1][y] + field[x + 1][y + 1] + field[x + 2][y + 1];
	}
	if (OOB(x + 1, y - 1) && OOB(x, y + 1)) {
		tmp2 = field[x][y] + field[x][y + 1] + field[x + 1][y] + field[x + 1][y - 1];
	}
	if (OOB(x + 2, y-1)) {
		tmp3 = field[x][y] + field[x + 1][y] + field[x + 1][y - 1] + field[x + 2][y - 1];
	}
	if (OOB(x + 1, y + 2)) {
		tmp4 = field[x][y] + field[x][y + 1] + field[x + 1][y + 1] + field[x + 1][y + 2];
	}
	Mtmp = max(max(max(tmp1, tmp2), tmp3), tmp4);
	return Mtmp;
}
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &field[i][j]);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			MAX = max(MAX, dlfwk(i, j));
			MAX = max(MAX, ahwk(i, j));
			MAX = max(MAX, spah(i, j));
			MAX = max(MAX, rldurwk(i, j));
			MAX = max(MAX, wpxm(i, j));
		}
	}
	printf("%d\n",MAX);
	return 0;
}