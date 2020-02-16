#include <iostream>
#include <deque>
#include <cstring>
using namespace std;

int N,M,T,a,x,d,k;
deque<int> dq[55];
 bool check[55][55];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> M >> T;
    for(int i=1; i<=N; i++) {
        for(int j=0; j<M; j++) {
            cin >> a;
            dq[i].push_back(a);
        }
    }
    
    while(T--){
        cin >> x >> d >> k;
        
        for(int i=x; i<=N; i+=x) {
            int rnum = k;
            while(rnum--) {
                if(d==0) {
                    int val = dq[i].back();
                    dq[i].push_front(val);
                    dq[i].pop_back();
                }
                else {
                    int val = dq[i].front();
                    dq[i].push_back(val);
                    dq[i].pop_front();
                }
            }
        }
        /* 회전 연산
        ---------------------------------------------*/
       
        memset(check,false,sizeof(check));
        int cnt = 0;
        /* 초기화
        ---------------------------------------------*/
        
        
        if(dq[N].front() > 0 && dq[N].front() == dq[N].back()) {
            check[N][0] = check[N][M-1] = true;
            cnt++;
        }
        
        for(int i=1; i<N; i++) {
            if(dq[i].front() > 0 && dq[i].front() == dq[i].back()) {
                check[i][0] = check[i][M-1] = true;
                cnt++;
            }
            if(dq[i].back() > 0 && dq[i].back() == dq[i+1].back()) {
                check[i][M-1] = check[i+1][M-1] = true;
                cnt++;
            }

            for(int j=0; j<dq[i].size()-1; j++) {
                if(dq[i][j] > 0){
                    if(dq[i][j] == dq[i][j+1]) {
                        check[i][j] = check[i][j+1] = true;
                        cnt++;
                    }
                    if(dq[i][j] == dq[i+1][j]) {
                        check[i][j] = check[i+1][j] = true;
                        cnt++;
                    }
                }
            }
        }
        for(int j=0; j<dq[N].size()-1; j++){
            if(dq[N][j]>0 && dq[N][j] == dq[N][j+1]){
                check[N][j] = check[N][j+1] = true;
                cnt++;
            }
        }
        
        if(dq[N].back() >0 && dq[N].back() == dq[N-1].back()) {
            check[N][M-1] = check[N-1][M-1] = true;
            cnt++;
        }
        /* 같은 값 찾고 있으면 cnt++, check[x][y] = true;
        -----------------------------------------------------------*/
        
        
        int sum = 0, many = 0;
        for(int i=1; i<=N; i++) {
            for(int j=0; j<dq[i].size(); j++) {
                if(cnt == 0) {
                    if(dq[i][j] > 0) {
                        sum += dq[i][j];
                        many++;
                    }
                }
                else
                    if(check[i][j]) dq[i][j]=0;
            }
        }
        /* 탐색하면서 같은 값이 있었다면 check배열에 표시해둔 좌표의 데이터를 지우고, 
        // 같은 값이 없었다면 0보다 큰 숫자의 갯수와 총합 계산한다.
        -------------------------------------------------------------*/

        if(cnt == 0 && many != 0) {
            double avg = (double) sum / many;
            
            for(int i=1; i<=N; i++) {
                for(int j=0; j<dq[i].size(); j++) {
                    if(dq[i][j] > 0) {
                        if(dq[i][j] > avg) {
                            dq[i][j]--;
                        }
                        else if(dq[i][j] < avg){
                            dq[i][j]++;
                        }
                    }
                }
            }
        /* 지워진것이 없으면서 원판의 모든 값이 0이 아니면 평균을 구하여 --,++한다.
        ------------------------------------------------------------*/
        }
    }
    
    int res = 0;
    for(int i = 1; i <= N; i++)
        for(int j = 0; j < M; j++)
            res += dq[i][j];
    cout << res << '\n';
    return 0;
}