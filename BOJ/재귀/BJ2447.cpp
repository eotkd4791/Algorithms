#include <iostream>
#include <algorithm>
using namespace std;

int N;
const int MAX = 2190;
char field[MAX][MAX];

void recur(int n, int x, int y) {

    if(n==1) {
        field[x][y] = '*';
        return;
    }
    else {
        int div_area = n/3;
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                if(i==1 && j==1) continue;
                recur(n/3, x + div_area*i, y + div_area*j);
            }
        }
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for(int i=0; i<MAX; i++) {
        fill(field[i], field[i]+MAX, ' ');
    }

    recur(N, 0, 0);

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cout << field[i][j];
        }
        cout << '\n';
    }
    return 0;
}
