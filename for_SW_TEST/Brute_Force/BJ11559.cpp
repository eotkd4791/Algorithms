//////////////////////////////////
/*
	BOJ11559 Puyo puyo
                               */
//////////////////////////////////
/*
queue를 하나 더 만들어서 지나가는 노드를
push해놓고 size()함수를 이용해서 
갯수를 세는 방식으로 풀었다.
*/

#include <iostream>
#include <queue>
#include <cstring>
#define H 12
#define W 6
using namespace std;

char field[14][8];
bool check[14][8];

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

typedef struct {
	int x;
	int y;
	char colour;
}node;

queue<node> q;//색깔탐색 큐
queue<node> ep;//지나간 노드(뿌요)를 저장하는 큐

bool OOB(int x, int y) {//범위 검사
	if (H > x && x >= 0 && 0 <= y && y < W)
		return true;
	return false;
}


void BFS(node p) {
	q.push(p);
	while (!q.empty()) {
		int ox = q.front().x;
		int oy = q.front().y;
		char oc = q.front().colour;

		ep.push({ ox,oy,oc });//큐사이즈 체크하는 식으로 몇번의 뿌요가 붙어있는지 확인.
		check[ox][oy] = 1;

		q.pop();

		for (int n = 0; n < 4; n++) {
			int nx = ox + dx[n];
			int ny = oy + dy[n];
			if (OOB(nx, ny) && field[nx][ny] == oc && !check[nx][ny]) {

				node point = { nx,ny,field[nx][ny] };
				q.push(point);
				check[nx][ny] = 1;
			}
		}
	}
}


void puyodrop() {//뿌요 정렬
	for (int j = 0; j < W; j++) {
		for (int i = 11; i >= 1; i--) {
			for (int k = i - 1; k >= 0; k--) {
				if (field[i][j] != '.') break;
				if (field[k][j] != '.') {
					field[i][j] = field[k][j];
					field[k][j] = '.';
					break;
				}
			}
		}
	}
}


int main() {

	
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> field[i][j];
		}
	}
	
	int chain = 0;//연쇄 횟수
	int checkbomb = 1;//폭발 횟수

	while (checkbomb != 0) {
		checkbomb = 0;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (field[i][j] == '.') continue;
				else {
					if (!check[i][j]) {
						node point = { i, j, field[i][j] };
						BFS(point);

						if (ep.size() < 4) {//4덩어리보다 적으면 큐를 pop시켜서 비운다.
							while (!ep.empty()) ep.pop();
						}

						else {//4덩어리보다 많거나 같으면 '.'으로 바꿔줌
							checkbomb++;
							while (!ep.empty()) {
								int xo = ep.front().x;
								int yo = ep.front().y;
								field[xo][yo] = '.';
								ep.pop();
							}
						}
					}
				}
			}
		}
		if (checkbomb > 0) chain++;
		puyodrop();
		memset(check, 0, sizeof(check));
	}
	cout << chain << '\n';
	return 0;
}
