#include <iostream>
#include <algorithm>
using namespace std;

int N, M, highest;
int tree[1000001];

int binarySearch(int start, int finish) { return (start + finish) / 2; }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;
    
    for(int i=0; i<N; i++) {
        cin >> tree[i];
        highest = max(highest, tree[i]);
    }
    
    int first = 0, last = highest;
    int ans = 0;
    
    while(first <= last) {
        int mid = binarySearch(first, last);
        
        long long sum = 0;
        for(int i = 0; i < N; i++) {
            int tmp = tree[i] - mid;
            if(tmp > 0) sum += tmp;
        }
        if(sum >= M) {
            first = mid + 1;
            ans = max(ans, mid);
        }
        else if(sum < M) {
            last = mid - 1;
        }
    }
    cout << ans << '\n';
    return 0;
}