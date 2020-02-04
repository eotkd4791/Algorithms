#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;

int N, M, a, fs;
typedef struct {
    int st;
    int rc;
    int rg;
}node;
node arr[22];
bool check[101];

bool cmp(node a, node b) {
    if(a.rc < b.rc) return true;
    else if(a.rc == b.rc) {
        if(a.rg < b.rg) return true;
        else return false;
    }
    else return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> M;
    
    int time = 1;
    while(M--) {
        cin >> a;
        if(check[a]){
            for(int i = 0; i < N; i++) {
                if(arr[i].st == a) {
                    arr[i].rc++;
                    break;
                }
            }
        }
        else {
            if(fs < N) {
                check[a] = true;
                arr[fs++] = {a, 1, time++};
            }
            else {
                sort(arr, arr + fs, cmp);
                check[arr[0].st] = false;
                arr[0] = {a, 1, time++};
                check[a] = true;
            }
        }
    }
    vector<int> ans;
    for(int i=0; i<N; i++)
        ans.push_back(arr[i].st);
    sort(ans.begin(), ans.end());
    for(int i=0; i<ans.size(); i++) {
        cout << ans[i];
        if(i!=ans.size()-1)
            cout << ' ';
        
    }
    return 0;
}