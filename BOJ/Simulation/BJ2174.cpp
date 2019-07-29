#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
using namespace std;

int A, B, N, M;
int field[101][101];

struct robot {
	int x;
	int y;
	char dir;
};
robot rb[101];

struct order {
	int rbnum;
	char rbord;
	int ordcnt;
};
order arr[101];

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };//NESW
char dr[] = { 'N','E','S','W' };
bool inb = 1;
int fr=0;

bool OOB(int ry, int rx) {
	if (A >= ry && ry >= 1 && 1 <= rx && rx <= B)
		return true;
	return false;
}

void sim(int rnum, int y, int x, char d, char ord, int cnt) {
	int dtmp; int ny = y; int nx = x;

	if (d == 'N')
		dtmp = 0;
	else if (d == 'E')
		dtmp = 1;
	else if (d == 'S')
		dtmp = 2;
	else if(d =='W')
		dtmp = 3;

	for (int i =0; i < cnt; i++) {
		if (ord == 'L') {
			if (dtmp == 0)
				dtmp = 3;
			else
				dtmp -= 1;
			rb[rnum].dir = dr[dtmp];
		}
		
		else if (ord == 'R') {
			if (dtmp == 3)
				dtmp = 0;
			else
				dtmp += 1;
			rb[rnum].dir = dr[dtmp];
		}

		else if (ord == 'F') {//F
			field[ny][nx] = 0;
			nx += dx[dtmp];
			ny += dy[dtmp];
			if (OOB(ny, nx)) {//¹üÀ§ ¾È
				if (field[ny][nx] == 0) {//ºó Ä­
					field[ny][nx] = rnum;
					rb[rnum].y = ny;
					rb[rnum].x = nx; 
					continue;
				}
				else {//·Îº¿°ú Ãæµ¹
					fr = field[ny][nx];
					return;
				}
			}

			else { //¹üÀ§ ¹Û
				inb = 0;
				return;
			}
		}
	}
}

int main() {
	scanf("%d %d", &A, &B);
	scanf("%d %d", &N, &M);

	int xx; int yy; char dd;
	for (int n = 1; n <= N; n++) {
		scanf("%d %d %c", &yy, &xx, &dd);
		field[yy][xx] = n;
		rb[n].y = yy;
		rb[n].x = xx;
		rb[n].dir = dd;
	}

	int rn; char ro; int rc;//·Îº¿ ¹øÈ£, ¸Û·É, ¹Ýº¹ È½¼ö
	for (int m = 0; m < M; m++) {
		scanf("%d %c %d", &rn, &ro, &rc);
		arr[m].rbnum = rn;
		arr[m].rbord = ro;
		arr[m].ordcnt = rc;
	}

	for(int m = 0; m < M; m++) {
		sim(arr[m].rbnum, rb[arr[m].rbnum].y, rb[arr[m].rbnum].x, rb[arr[m].rbnum].dir, arr[m].rbord, arr[m].ordcnt);
		
		if (!inb) {
			printf("Robot %d crashes into the wall\n", arr[m].rbnum);
			return 0;
		}
		if (fr != 0) {
			printf("Robot %d crashes into robot %d\n", arr[m].rbnum, fr);
			return 0;
		}
	}
	printf("OK\n");
	return 0;
}