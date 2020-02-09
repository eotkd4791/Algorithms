#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int arr[30];
vector<string> v;

bool cmp(int a, int b) { return a > b; }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> N;
    
    string str;
    for(int i=0; i<N; i++) {
        cin >> str;
        v.push_back(str);
    }
    
    for(int i=0; i < N; i++) {
        str = v[i];
        int len = (int) str.size();
        int pwr = 1;
        
        for(int j = len - 1; j>=0; j--) {
            int tmp = str[j]-'A';
            arr[tmp] += pwr;
            pwr *= 10;
        }
    }
    sort(arr, arr+26, cmp);
    
    int ans = 0;
    int num = 9;
    for(int i=0; i<26; i++) {
        if(arr[i] == 0) break;
        ans += (arr[i] * num);
        num--;
    }
    cout << ans << '\n';
    return 0;
}