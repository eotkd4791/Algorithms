#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>
#include <queue>
#include <utility>
#include <functional>
#include <map>
#include <set>
using namespace std;

int T, n;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  
  cin >> T;
  while(T--) {
    
    int arr[101]={};
    
    cin >> n; 
    bool flag = true;
    for(int i=0; i<n; i++) {
      cin >> arr[i];
      if(i>0 && arr[i-1] != arr[i]) flag = false;
    }
    if(flag) cout << "YES\n";
    else {
      bool cant = false;
      for(int i=1; i<n; i++) {
        if(abs(arr[i-1]-arr[i]) % 2 != 0) {
          cant = true;
          cout << "NO\n";
          break;
        }
      }
      if(!cant) cout << "YES\n";
    }
  }
  return 0;
}
