/*경로 찾기*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
vector<vector<int>>v(110);
int N,arr[110][110],check[110];

int BFS(int start, int target) {
    queue<int>q={};                     //큐 초기화 까먹지 않기 
    check[start]=1;
    q.push(start);
    while(q.empty()==0) {
        int now=q.front();
        q.pop();
        for(int k=0; k<v[now].size(); k++) {
            if(v[now][k]==target) return 1; //이 부분 잘 기억하기
            int next=v[now][k];
            if(check[next]==0) {
                check[next]=1;
                q.push(next);
            }
        }
    }
    return 0;
}

int main() {
    scanf("%d",&N);
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            scanf("%d",&arr[i][j]);
            if(arr[i][j]==1) v[i].push_back(j);
        }
    }
    for(int i=1; i<=N; i++) {
        for (int j=1; j<=N; j++) {
            printf("%d ",BFS(i,j));
            memset(check,0,sizeof(check));
        }
        printf("\n");
    }
    return 0;
}
