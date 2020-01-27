#include <iostream>
#include <utility>
#include <algorithm>
#define INF 987654321
using namespace std;

int N, MIN = INF, field[22][22],tmp[22][22];
pair<int,int> p[4];

inline void calc() {
    int sum[5]={};
    for(int i=0; i<N; i++)
        for(int j =0; j<N; j++)
            sum[tmp[i][j]-1] +=field[i][j];
    
    int tMIN = *min_element(sum, sum+5);
    int tMAX = *max_element(sum, sum+5);
    MIN = min(MIN, tMAX-tMIN);
}

inline bool line(int x, int y, int d1, int d2) {
    if(x+d1+d2 >= N) return false;
    if(y-d1 < 0) return false;
    if(y+d2 >= N) return false;
    return true;
}

inline void dist(int x, int y, int d1, int d2) {
    for(int i=0; i<N; i++) fill(tmp[i],tmp[i]+N,5);
    
    //1
    int idx=0;
    for(int i=0; i<p[1].first; i++) {
        if(p[0].first<=i) idx++;
        for(int j=0; j<=p[0].second-idx; j++) tmp[i][j] = 1;
    }
    //2
    idx=0;
    for(int i=0; i<=p[2].first; i++) {
        if(p[0].first<i) idx++;
        for(int j=p[0].second+1+idx; j<N; j++) tmp[i][j] = 2;
    }
    //3
    idx=0;
    for(int i=N-1; i>=p[1].first; i--) {
        if(p[3].first>i) idx++;
        for(int j=0; j<p[3].second-idx; j++) tmp[i][j] = 3;
    }
    //4
    idx=0;
    for(int i=N-1; i>p[2].first; i--) {
        if(p[3].first>=i) idx++;
        for(int j=p[3].second+idx; j<N; j++) tmp[i][j] = 4;
    }
    calc();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> N;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cin >> field[i][j];
    
    for(int i=0; i<N; i++) {
        for(int j=1; j<N; j++) {
            for(int d1=1; d1<=j; d1++) {
                for(int d2=1; d2<N-j; d2++) {
                    if(line(i,j,d1,d2)) {
                        p[0] = make_pair(i,j);
                        p[1] = make_pair(i+d1,j-d1);
                        p[2] = make_pair(i+d2,j+d2);
                        p[3] = make_pair(i+d1+d2,j+(d2-d1));
                        dist(i,j,d1,d2);
                    }
                }
            }
        }
    }
    cout << MIN << '\n';
    return 0;
}
