#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string N;

bool cmp(char a, char b) { return a>b; }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> N;
    
    bool existZero=false;
    long long eachDgt=0;
    
    for(int i = 0; i<N.size(); i++) {
        int tmp = N[i]-'0';
        eachDgt += tmp;
        if(tmp == 0) existZero=true;
    }
    if(eachDgt % 3 != 0 || !existZero) {
        cout << "-1" << '\n';
        return 0;
    }
    else {
        sort(N.begin(), N.end(), cmp);
        cout << N << '\n';
    }
    return 0;
}