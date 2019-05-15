//////////////////////////////////////
/*
         BOJ17143 낚시왕

//////////////////////////////////////
*/
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100
using namespace std;

int R, C, M;
int sum;
int dx[] = { 0,-1,1,0,0 };
int dy[] = { 0,0,0,1,-1 };

typedef struct {
	int X;//x
	int Y;//y
	int Sp;//속도 
	int D;//방향 
	int Sz;//크기 
	int num;//상어 번호 
	bool alive;//살았는지 죽었는지 
}shark;
vector<shark> v;//상어의 정보를 저장한다. 
vector<int> map[MAX][MAX];//상어 번호를 저장한다. 

bool compare(int a, int b) {//크기가 큰 상어를 앞으로 오게 정렬 
	if (v[a].Sz > v[b].Sz)
		return true;
	return false;
}
bool check() {//맵에 상어가 없다면 false 반환(반복문 탈출 조건) 
	for (int i = 0; i < v.size(); i++) {
        if (v[i].alive == true) return true;
    }
    return false;
}

void fishing(int yy) {//낚시꾼이 상어를 잡고 크기를 sum에 더한다. 
	for(int xx=0; xx<R; xx++) {
		if(map[xx][yy].size()==1) {
			sum += v[map[xx][yy][0]].Sz;
			v[map[xx][yy][0]].alive=false;//상어를 죽이고 
			map[xx][yy].clear();//좌표 초기화를 해준다. 
			break;//반복문 탈출  한마리만 잡으니깐 
		}
	}
}

void movingshark() {
	for (int i = 0; i < v.size(); i++) {
		if (!v[i].alive) continue;
		int ox = v[i].X;
		int oy = v[i].Y;
		map[ox][oy].clear();//상어를 맵에서 다 지우고 
	}
	for (int i = 0; i < v.size(); i++) {//살이있는 상어의 좌표를 가져와서  
		if (!v[i].alive) continue;
		int xx = v[i].X;
		int yy = v[i].Y;
		int dd = v[i].D;
		int ss = v[i].Sp;

		if (dd == 1 || dd == 2) {//방향 상 하 
			for (int j = 0; j < ss; j++) {
				int nx = xx + dx[dd];
				int ny = yy + dy[dd];
				if (nx < 0) {
					dd = 2;
					nx += 2;
				}
				if (nx >= R) {
					dd = 1;
					nx -= 2;
				}
				xx = nx;
				yy = ny;
			}
		}
		else if (dd == 3 || dd == 4) {//방향 좌 우	 
			for (int j = 0; j < ss; j++) {
				int nx = xx + dx[dd];
				int ny = yy + dy[dd];
				if (ny < 0) {
					dd = 3;
					ny += 2;
				}
				if (ny >= C) {
					dd = 4;
					ny -= 2;
				}
				xx = nx;
				yy = ny;
			}
		}
		v[i].X = xx;
		v[i].Y = yy;
		v[i].D = dd;
		map[xx][yy].push_back(i);
	}
}

void killshark() {//한 좌표에 상어가 여러마리라면 크기가 가장 큰 상어가 나머지 상어를 다 먹어버린다. 
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j].size() > 1) {
				sort(map[i][j].begin(), map[i][j].end(), compare);//크기가 가장 큰 상어가 MAP[X][Y][0]에 위치하도록 정렬 
				int ll = map[i][j][0];//
				for (int k = 1; k < map[i][j].size(); k++) {
					v[map[i][j][k]].alive = false;
					v[map[i][j][k]].X = -1;
					v[map[i][j][k]].Y = -1;
				}
				map[i][j].clear();
				map[i][j].push_back(v[ll].num);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> R >> C >> M;

	if (M == 0) {//상어 수가 0마리 일때 0출력 후 종료
		cout << '0';
		return 0;
	}
	int r, c, s, d, z;
	for (int m = 0; m < M; m++) {//입력
		shark aa;
		cin >> r >> c >> s >> d >> z;
		r -= 1;
		c -= 1;
		aa.X = r;
		aa.Y = c;
		aa.Sp = s;
		aa.D = d;
		aa.Sz = z;
		aa.num = m;
		aa.alive = true;
		v.push_back(aa);
		map[r][c].push_back(m);
	}
	for (int i = 0; i < C; i++) {//낚시꾼 열->이동
		if(!check()) break;
		fishing(i);
		movingshark();
		killshark();
	}
	cout << sum;
	return 0;
}
