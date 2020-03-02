#include<iostream>
#include <cstring>
using namespace std;

char str[121], newStr[121];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n, flag, ans = 0;
    
    cin >> n;
    
    for(int i=1; i<=n; i++) cin >> str[i];
    
    
    for (char ch = 'z'; ch > 'a'; ch -= flag) {
        
        int m = 0; flag = 1;
        
        for (int i = 1; str[i]; i++) {
            if (str[i] != ch) newStr[++m] = str[i];
            else {
                if (str[i - 1] == str[i] - 1 || str[i] - 1 == str[i + 1]) {
                    ans++;
                    flag = 0;
                }
                else newStr[++m] = str[i];
            }
        }
        memset(str, 0, sizeof(str));
        for (int i = 1; i <= m; i++) str[i] = newStr[i];
        n = m;
    }
    cout << ans << '\n';
    return 0;
}
