#include <iostream>
#include <string>
#include <cmath>
#define endl '\n'
#define INF 1000000
using namespace std;

int K;
string P;
bool pCheck[INF+10];

bool isGood(int pn) {
    int ret = 0;
    for(int i=0; i<(int) P.size(); i++)
        ret = (ret * 10 + P[i] -'0') % pn;
    
    if(ret==0) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> P >> K;
    
    pCheck[0] = pCheck[1] = true;
    
    for(int i=2; i<=sqrt(INF+3); i++) {
        if(pCheck[i]) continue;
        for(int j = i * i; j<=INF+3; j+=i) {
            pCheck[j] = true;
        }
    }
    
    bool flag = false;
    int minNum  = 987654321;
    
    for(int i=2; i<K; i++) {
        if(pCheck[i]) continue;
        if(isGood(i)) {
            flag = true;
            minNum = minNum > i ? i : minNum;
        }
    }
    if(!flag) cout << "GOOD" << endl;
    else cout << "BAD" << ' ' << minNum << endl;
    return 0;
}
