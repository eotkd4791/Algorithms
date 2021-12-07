#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#define INF 1000000
using namespace std;

int a;
bool check[INF+1];

typedef struct {
    int aa;
    int bb;
    int cc;
}ctn;
const string fail = "Goldbach's conjecture is wrong.";

void getPrime() {
    check[1] = check[INF] = true;
    
    for(int i = 2; i <= sqrt(INF); i++) {
        if(check[i]) continue;
        for(int j=i+i; j<=INF; j+=i)
            check[j]=true;
        
    }
    check[2] = true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    getPrime();

    while(1) {
        cin >> a;

        if(a==0) break;
        
        ctn ans = {0, 0, 0};
        for(int i=3; i <= a; i++) {
            if(check[i]) continue;

            int b = i;
            int c = a - b;
            if(!check[c]) {
                if(b > c) swap(b,c);
                if((ans.cc - ans.bb) <= c - b) ans = {a, b, c};
                break;
            }
        }
        if(ans.aa > 0 && ans.bb > 0 && ans.cc > 0)
            cout << ans.aa << " = " << ans.bb << " + " << ans.cc << '\n';

        else
            cout << fail << '\n';
    }
    return 0;
}
