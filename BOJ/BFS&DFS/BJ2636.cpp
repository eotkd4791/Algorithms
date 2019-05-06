/////////////////////////////////////
/*
            BOJ2636 ДЎБо 

////////////////////////////////////
*/
#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
#include <vector>
using namespace std;

int N,M;
int field[111][111];
int c[111][111];
bool check[111][111];
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};
queue<pair<int,int> > q;
vector<int> v;
int howmany,ans;

bool OOB(int x,int y) {
	if(M > y && y >= 0 && 0 <= x && x < N)
		return true;
	return false;
}

void cheese_melting() {
	howmany=v.size();
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			if(c[i][j]>=1) {
				field[i][j]=0;
				v.pop_back();
			}
		}
	}
}

void BFS(int x, int y) {
	check[x][y]=1;
	q.push(make_pair(x,y));
	while(!q.empty()) {
		int ox=q.front().first;
		int oy=q.front().second;
		q.pop();
		for(int n=0; n<4; n++) {
			int nx=ox+dx[n];
			int ny=oy+dy[n];
			if(OOB(nx,ny) && !check[nx][ny]) {
				if(field[nx][ny]==0) {
					check[nx][ny]=1;
					q.push(make_pair(nx,ny));
				}
				if(field[nx][ny]==1) {
					c[nx][ny]++;
				}
			}
		}	
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for(int i=0; i<N; i++) {
		for(int j=0; j<M; j++) {
			cin >> field[i][j];
			if(field[i][j]==1) v.push_back(field[i][j]);
		}
	}
	while(v.size()!=0){
		BFS(0,0);
		cheese_melting();
		memset(check,0,sizeof(check));
		memset(c,0,sizeof(c));
		ans++;
	}
	cout << ans << '\n' << howmany;
	return 0;
}
