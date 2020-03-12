#include <iostream>
using namespace std;

int T, n;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  
  cin >> T;
  while(T--) {
    cin >> n;
    
    int arr[5005]={};
    
    for(int i=0; i<n; i++) {
      cin >> arr[i];

    bool flag = false;
    for(int i=0; i<n; i++) {
      for(int j=i+2; j<n; j++) {
        if(arr[i] == arr[j]) {
          flag = true;
          break;
        }
      }
      if(flag) {
        cout << "YES\n";
        break;
      }
    }  
    if(!flag) cout << "NO\n";
  }
  return 0;
}
