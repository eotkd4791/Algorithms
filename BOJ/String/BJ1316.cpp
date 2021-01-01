#include <iostream>
#include <map>
using namespace std;

int n;
string arr[101];
map<char, bool> mappedString;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i=0; i<n; i++) cin >> arr[i];

  int MAX = n;

  for(int i=0; i<n; i++) {
    char latest;
    for(int j=0; j<arr[i].size(); j++) {
      char str = (char) arr[i][j];

      if(mappedString.find(str)->second) {
        if(latest == str) {
          MAX--;
          break;
        }
      }
      else mappedString.insert(make_pair(str, true));
      latest = str;
    }
  }
  
  cout << MAX << '\n';
  return 0;
}