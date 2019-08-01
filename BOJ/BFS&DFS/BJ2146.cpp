
//////////////////////////////////////////
/*
   BOJ2146 다리만들기
*/
//////////////////////////////////////////
/*board배열은 간척사업을 하면서 새롭게 확장하는 부분을 출발점이 된 섬의 번호를 붙여서 저장한다.
check배열은 섬 번호 매길때는 memoization용도로 쓰지만,
memset함수로 초기화를 한 이후에는 간척사업의 횟수를 표시하는 용도로 쓴다.*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#define INF 999999
using namespace std;

int N, field[110][110], check[110][110], sub[110][110];
int num = 1, MIN = INF, ans;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
queue<pair<int, int> > Q;

void numbering_BFS(int x, int y) {
	queue<pair<int, int> > q = {};
	check[x][y] = 1;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		int xnow = q.front().first;
		int ynow = q.front().second;
		q.pop();
		sub[xnow][ynow] = num;
		for (int n = 0; n < 4; n++) {
			int nx = xnow + dx[n];
			int ny = ynow + dy[n];
			if (nx >= 0 && ny >= 0 && ny < N && nx < N &&check[nx][ny] == 0 && field[nx][ny] != 0) {
				check[nx][ny] = 1;
				q.push({ nx, ny });
			}
		}
	}
}

void BFSforFill() {//간척사업 / 이미 큐에 다 들어가있기 때문에 인자값 필요없음
	int level = 0; //간척사업 횟수
	int round = check[Q.front().first][Q.front().second]; // 하위그룹으로 가면서 ++
	//check 큐에 들어간 값의 인덱스(자리번호) //레벨을 구분하기 위해서
	while (!Q.empty()) {
		int xnowfill = Q.front().first;
		int ynowfill = Q.front().second;

		if (check[xnowfill][ynowfill] > round) {
			level++; //간척사업 다음 라운드로 넘어가기
			round++; //다음 하위 그룹 
		}

		Q.pop();
		for (int n = 0; n < 4; n++) {
			int xnextfill = xnowfill + dx[n];
			int ynextfill = ynowfill + dy[n];

			if (sub[xnextfill][ynextfill] != 0 && check[xnextfill][ynextfill] != 0) {
				if (sub[xnowfill][ynowfill] != sub[xnextfill][ynextfill]) {
					ans = check[xnowfill][ynowfill] + check[xnextfill][ynextfill];
					MIN = min(MIN, ans);
				}
			}//최솟값 구하기

			if (xnextfill >= 0 && ynextfill >= 0 && xnextfill < N && ynextfill < N) {
				if (check[xnextfill][ynextfill] == 0 && sub[xnextfill][ynextfill] == 0) {
					check[xnextfill][ynextfill] = level + 1;//이번 라운드 간척끝냈다는 뜻.
					sub[xnextfill][ynextfill] = sub[xnowfill][ynowfill];
					Q.push({ xnextfill, ynextfill });
				}
			}//라운드 진행
		}
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &field[i][j]);
		}
	}//입력

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (field[i][j] != 0 && check[i][j] == 0) {
				numbering_BFS(i, j);
				num++;
			}
		}
	}//섬 번호에 번호 매기기
	memset(check, 0, sizeof(check));

	for (int i = 0; i < N; i++) {//3중for문 탐색하면서 단지의 테두리 부분들을 큐에 처음 박는 코드
		for (int j = 0; j < N; j++) {
			for (int n = 0; n < 4; n++) {
				int xnext = i + dx[n];
				int ynext = j + dy[n];
				if (sub[i][j] != 0 && sub[xnext][ynext] == 0) {//바다가 옆에 있는지 확인 후
					Q.push({ i, j });//바다와 인접한 테두리의 좌표를 큐에 모두 넣고 시작.
					break;//두개의 바다와 인접한 지점을 중복으로 큐에 넣지않기 위해서
						  //한번 큐에 넣으면 반복문을 빠져나가야 하기 때문에 break를 이용하여 for문하나를 벗어났다가 다시 들어옴.
				}
			}
		}
	}//큐에 각 섬들을 한번에 집어넣는 이유 - 동시에 간척을 해야 정확한 거리를 잴 수 있음.

	BFSforFill();
	printf("%d\n", MIN);
	return 0;
} 
