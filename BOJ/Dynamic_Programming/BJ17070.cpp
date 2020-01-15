#include <iostream>
using namespace std;

int N, field[20][20], arr[20][20][3];
const int dx[]={0,-1,-1};
const int dy[]={-1,-1,0};
inline bool OOB(int xx, int yy) { return (1 <= xx && xx <= N && N >= yy && yy >= 1); }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> N;
    for (int i=1; i<=N; i++)
        for (int j=1; j<=N; j++)
            cin >> field[i][j];
    
    if(field[1][3]==1) {
        cout << "0";
        return 0;
    }
    arr[1][3][0]=1;
    if(field[2][2]==0) arr[2][3][1]=1;
    for(int nx=1; nx<=N; nx++) {
        for(int ny=3; ny<=N; ny++) {
            if((nx == 1 && ny == N) || field[nx][ny]==1) continue;
            for(int dir = 0; dir < 3; dir++) {
                int ox=nx+dx[dir];
                int oy=ny+dy[dir];
                if(!OOB(ox,oy) || field[ox][oy]==1) continue;
                if(nx != N && ny == N) {
                    switch (dir) {
                        case 1:
                            if(field[nx-1][ny]==0 && field[nx][ny-1]==0)
                                for(int i=0; i<3; i++)
                                    arr[nx][ny][1]+=arr[ox][oy][i];
                            break;
                        case 2:
                            arr[nx][ny][2]+=arr[ox][oy][2]+arr[ox][oy][1];
                            break;
                        default:
                            break;
                    }
                }
               else if(nx == N && ny != N) {
                    switch (dir) {
                        case 1:
                            if(field[nx-1][ny]==0 && field[nx][ny-1]==0)
                                for(int i=0; i<3; i++)
                                    arr[nx][ny][1]+=arr[ox][oy][i];
                            break;
                        case 0:
                            arr[nx][ny][0]+=arr[ox][oy][0]+arr[ox][oy][1];
                            break;
                        default:
                            break;
                    }
                }
               else {
                   switch (dir) {
                       case 1:
                           if(field[nx-1][ny]==0 && field[nx][ny-1]==0)
                               for(int i=0; i<3; i++)
                                   arr[nx][ny][1] += arr[ox][oy][i];
                           break;
                       case 2:
                           arr[nx][ny][2] += arr[ox][oy][1] + arr[ox][oy][2];
                           break;
                       default:
                           arr[nx][ny][0] += arr[ox][oy][0] + arr[ox][oy][1];
                           break;
                   }
               }
            }
        }
    }
    int ans = arr[N][N][0] + arr[N][N][1] + arr[N][N][2];
    cout << ans << '\n';
    return 0;
}