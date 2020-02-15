#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

int t,n,m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    string str[101]={};
    string ans;
    map<string, bool> mm;
    vector<string> v;
    
    for(int i=0; i<n; i++) {
        cin >> str[i];
        
        string rvs = str[i];
        reverse(rvs.begin(), rvs.end());
        
        if(str[i] == rvs) ans = str[i];
        
        else  {
            if(mm.count(rvs)){
                mm.insert({ str[i], true });
                mm[rvs] = false;
            }
            else {
                mm.insert({ str[i], false });
            }
        }
    }
    for(map<string,bool>::iterator iter = mm.begin(); iter!=mm.end(); iter++) {
        if(iter->second) {
            string tmp = iter->first;
            string rtmp = tmp;
            
            reverse(rtmp.begin(), rtmp.end());
            
            string temp = tmp;
            temp+=ans;
            temp += rtmp;
            ans = temp;
            
        }
    }
    cout << ans.size() << '\n';
    if(ans.size() != 0)
        cout << ans << '\n';
    return 0;
}
