#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    string str;
    
    cin >> str;
    
    int cnt = 0;
    
    for(int i=0; i< (int) str.size(); i++) {
        if(str[i] == '(') {
            for(int j = (int) str.size()-1; j>i; j--) {
                if(str[j] == ')') {
                    str[i] = '0';
                    str[j] = '0';
                    cnt+=2;
                    break;
                }
                if(i == j) break;
            }
        }
    }
    if(cnt>0) {
        cout << 1 << '\n' << cnt << '\n';
        for(int i=0; i<str.size(); i++)
            if(str[i] == '0') cout << i + 1 << ' ';
        cout << '\n';
    }
    else cout << 0 << '\n';
    return 0;
}
