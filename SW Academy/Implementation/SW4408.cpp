#include <iostream>
#include <utility>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int T,N;
    
    cin >> T;
    for(int t = 1; t<=T; t++) {
        cin >> N;
        
        int a, b,MAX=0;
        pair<int,int> arr[202]={};
        priority_queue<int, vector<int>, greater<int> > pq;
        
        for(int i=0; i<N; i++) {
            cin >> a >> b;
            
            if(a>b) swap(a,b);
            arr[i] = make_pair(a,b);
        }
        sort(arr,arr+N);
        for(int j=0; j<N; j++) {
                int s = arr[j].first;
                int e = arr[j].second;
                
                if(pq.empty()) pq.push(e);
                else {
                    if(s%2==0) s--;
                    if(pq.top() < s) {
                        pq.pop();
                        pq.push(e);
                    }
                    else pq.push(e);
                }
                int sz = (int) pq.size();
                MAX = max(MAX, sz);
            }
        cout << '#' << t << ' ' << MAX << '\n';
    }
    return 0;
}
