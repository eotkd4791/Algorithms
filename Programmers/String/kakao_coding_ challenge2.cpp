#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>
using namespace std;

vector<int> solution(string s) {   
    int MAX = 0; int cnt[100001] = {}; string tmp = ""; int cpc = 0;
    memset(cnt, -1, sizeof(cnt));
    for(int i=0; i<s.size(); i++) {
        if(s[i] == '{') continue;

        else if(s[i] == '}' || s[i] == ',') {
            if(tmp != "") {
                int idx = atoi(tmp.c_str());
                MAX = max(MAX, idx);
                if(cnt[idx] == -1) {
                    cpc++;
                    cnt[idx] =  0;
                }
                cnt[idx]++;
                tmp="";
            }
        }
        else tmp += s[i];
    }
    vector<int> answer(cpc);
    for(int i=1; i<=MAX; i++) 
        if(cnt[i] > 0) answer[cpc - cnt[i]] = i;
    return answer;
}