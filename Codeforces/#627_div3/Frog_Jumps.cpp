#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int T;
string str;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin >> T;
    
    while(T--) {
        cin >> str;
        int ans=0, cnt=0;
        for(int i=0; i<str.size(); i++) {
            cnt++;
            if(str[i] == 'R') {
                ans=max(ans,cnt);
                cnt=0;
            }
        }
        cout << max(ans,++cnt) << '\n';
    }
    return 0;
}
