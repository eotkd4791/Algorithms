///////////////////////////////
/*
        BOJ15683 감시
                             */
///////////////////////////////
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

const int INF = 9999999;
int N, M;
int field[10][10];
int arr[10][10];//복사하기위한 배열
int MIN = INF;//최소값
int num;//CCTV갯수
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int dir[8];//카메라의 방향을 저장하는 배열, 인덱스+1은 카메라의 번호(순서)를 의미
vector<int> v;//카메라 종류 저장하는 벡터
vector<pair<int, int> > xy;//카메라가 있는 좌표(위치)저장하는 벡터

bool OOB(int a, int b) {//경계검사
	if (N > a && a >= 0 && 0 <= b && b < M)
		return true;
	return false;
}

void cpy(int a[10][10], int b[10][10]) {//맵복사,리셋할때 쓰는 함수
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			b[i][j] = a[i][j];
		}
	}
}

void DFS(int x, int y, int cam, int drt) {
	//pickdir함수에서 받아온 방향대로 CCTV를 돌려서 field에 
	//CCTV가 닿는 곳에 기록하는 함수
	if (field[x][y] == 6) return;
	if(field[x][y]==0)
		field[x][y] = cam;

	if (cam == 1) {//CCTV1
		if (drt == 0) {//방향0일때
			int nx = x + dx[0];
			int ny = y + dy[0];//경우의 수가 2가지
			if(OOB(nx,ny) && field[nx][ny]!=6)
				DFS(nx, ny, 1, 0);
		}
		if (drt == 1) {//방향1일때
			int nx = x + dx[1];
			int ny = y + dy[1];
			if (OOB(nx, ny) && field[nx][ny] != 6)
				DFS(nx, ny, 1, 1);
		}
		if (drt == 2) {//방향2일때
			int nx = x + dx[2];
			int ny = y + dy[2];
			if (OOB(nx, ny) && field[nx][ny] != 6)
				DFS(nx, ny, 1, 2);
		}
		if (drt == 3) {//방향3일때
			int nx = x + dx[3];
			int ny = y + dy[3];
			if (OOB(nx, ny) && field[nx][ny] != 6)
				DFS(nx, ny, 1, 3);
		}
	}
	if (cam == 2) {//CCTV2
		if (drt == 0 || drt == 2) {
			int nx = x + dx[0];
			int ny = y + dy[0];
			int rx = x + dx[2];
			int ry = y + dy[2];
			if (OOB(nx, ny) && field[nx][ny] != 6)
				DFS(nx, ny, 1, 0);
			if (OOB(rx, ry) && field[rx][ry] != 6)
				DFS(rx, ry, 1, 2);
		}
		if (drt == 1 || drt==3) {
			int nx = x + dx[1];
			int ny = y + dy[1];
			int rx = x + dx[3];
			int ry = y + dy[3];
			if (OOB(nx, ny) && field[nx][ny] != 6)
				DFS(nx, ny, 1, 1);
			if (OOB(rx, ry) && field[rx][ry] != 6)
				DFS(rx, ry, 1, 3);
		}
	}
	if (cam == 3) {//CCTV3
		if (drt == 0) {
			int nx = x + dx[0];
			int ny = y + dy[0];
			int rx = x + dx[3];
			int ry = y + dy[3];
			if (OOB(nx, ny) && field[nx][ny] != 6)
				DFS(nx, ny, 1, 0);
			if (OOB(rx, ry) && field[rx][ry] != 6)
				DFS(rx, ry, 1, 3);
		}
		if (drt == 1) {
			int nx = x + dx[0];
			int ny = y + dy[0];
			int rx = x + dx[1];
			int ry = y + dy[1];
			if (OOB(nx, ny) && field[nx][ny] != 6)
				DFS(nx, ny, 1, 0);
			if (OOB(rx, ry) && field[rx][ry] != 6)
				DFS(rx, ry, 1, 1);
		}
		if (drt == 2) {
			int nx = x + dx[2];
			int ny = y + dy[2];
			int rx = x + dx[1];
			int ry = y + dy[1];
			if (OOB(nx, ny) && field[nx][ny] != 6)
				DFS(nx, ny, 1, 2);
			if (OOB(rx, ry) && field[rx][ry] != 6)
				DFS(rx, ry, 1, 1);
		}
		if (drt == 3) {
			int nx = x + dx[3];
			int ny = y + dy[3];
			int rx = x + dx[2];
			int ry = y + dy[2];
			if (OOB(nx, ny) && field[nx][ny] != 6)
				DFS(nx, ny, 1, 3);
			if (OOB(rx, ry) && field[rx][ry] != 6)
				DFS(rx, ry, 1, 2);
		}
	}
	if (cam == 4) {//CCTV4
		if (drt == 0) {
			int nx = x + dx[3];
			int ny = y + dy[3];
			int rx = x + dx[2];
			int ry = y + dy[2];
			int cx = x + dx[0];
			int cy = y + dy[0];
			if (OOB(nx, ny) && field[nx][ny] != 6)
				DFS(nx, ny, 1, 3);
			if (OOB(rx, ry) && field[rx][ry] != 6)
				DFS(rx, ry, 1, 2);
			if (OOB(cx, cy) && field[cx][cy] != 6)
				DFS(cx, cy, 1, 0);
		}
		if (drt == 1) {
			int nx = x + dx[3];
			int ny = y + dy[3];
			int rx = x + dx[1];
			int ry = y + dy[1];
			int cx = x + dx[0];
			int cy = y + dy[0];
			if (OOB(nx, ny) && field[nx][ny] != 6)
				DFS(nx, ny, 1, 3);
			if (OOB(rx, ry) && field[rx][ry] != 6)
				DFS(rx, ry, 1, 1);
			if (OOB(cx, cy) && field[cx][cy] != 6)
				DFS(cx, cy, 1, 0);
		}
		if (drt == 2) {
			int nx = x + dx[1];
			int ny = y + dy[1];
			int rx = x + dx[2];
			int ry = y + dy[2];
			int cx = x + dx[0];
			int cy = y + dy[0];
			if (OOB(nx, ny) && field[nx][ny] != 6)
				DFS(nx, ny, 1, 1);
			if (OOB(rx, ry) && field[rx][ry] != 6)
				DFS(rx, ry, 1, 2);
			if (OOB(cx, cy) && field[cx][cy] != 6)
				DFS(cx, cy, 1, 0);
		}
		if (drt == 3) {
			int nx = x + dx[3];
			int ny = y + dy[3];
			int rx = x + dx[2];
			int ry = y + dy[2];
			int cx = x + dx[1];
			int cy = y + dy[1];
			if (OOB(nx, ny) && field[nx][ny] != 6)
				DFS(nx, ny, 1, 3);
			if (OOB(rx, ry) && field[rx][ry] != 6)
				DFS(rx, ry, 1, 2);
			if (OOB(cx, cy) && field[cx][cy] != 6)
				DFS(cx, cy, 1, 1);
		}
	}
	if (cam == 5) {
		int nx = x + dx[3];
		int ny = y + dy[3];
		int rx = x + dx[2];
		int ry = y + dy[2];
		int cx = x + dx[1];
		int cy = y + dy[1];
		int vx = x + dx[0];
		int vy = y + dy[0];
		if (OOB(nx, ny) && field[nx][ny] != 6)
			DFS(nx, ny, 1, 3);
		if (OOB(rx, ry) && field[rx][ry] != 6)
			DFS(rx, ry, 1, 2);
		if (OOB(cx, cy) && field[cx][cy] != 6)
			DFS(cx, cy, 1, 1);
		if (OOB(vx, vy) && field[vx][vy] != 6)
			DFS(vx, vy, 1, 0);
	}//모든 종류의 CCTV를 나눠보면 결국엔 CCTV1의 방향과 같았다. 그래서 DFS함수 인자 중, cam자리에 1을 계속해서 넣어 호출했다.
}

void ycsm() {//you can't see me 함수 CCTV가 감시할 수 없는 사각지대 세는 함수
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (field[i][j] == 0) {
				cnt++;
			}
		}
	}
	if (MIN > cnt) MIN = cnt;
	cpy(arr, field);
	return;
}

void CCTV() {//CCTV의 갯수만큼 반복문을 돌리면서 DFS함수에 꽂아 넣는 함수
	for (int i = 0; i < num; i++) {
		int tmp = v[i];
		DFS(xy[i].first, xy[i].second, tmp, dir[i]);
	}
	ycsm();
	return;
}

void pickdir(int a) {//방향이 나올 수 있는 모든 경우의 수를 재귀호출로 뽑아내는 함수
	if (a == num) {
		CCTV();
		return;
	}
	for (int i = 0; i < 4; i++) {
		dir[a] = i;
		pickdir(a + 1);
		dir[a] = 0;
	}
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &field[i][j]);
			if (0 < field[i][j] && field[i][j] < 6) {//CCTV가 있으면
				num++;//CCTV갯수 저장
				v.push_back(field[i][j]);//CCTV 카메라 종류 저장
				xy.push_back({ i,j });//CCTV 카메라 좌표
			}
		}
	}
	cpy(field, arr);//입력받은 2차원 배열field를 arr에 복사한다.
	pickdir(0);//재귀호출을 이용한 완전탐색으로 CCTV갯수 만큼 0~4 까지 뽑아서 dir배열에 저장하는 함수
	printf("%d\n", MIN);
	return 0;
}