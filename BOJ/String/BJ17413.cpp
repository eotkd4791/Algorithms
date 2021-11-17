#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string S;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin.clear();
  getline(cin, S);

  int Start = 0;
  bool OpenBracket = false;
  for(int i=0; i<S.size(); i++) {
    if(S[i] == '<') {
      reverse(S.begin() + Start, S.begin() + i);
      OpenBracket = true;
    }
    else if(S[i] == '>') {
      OpenBracket = false;
      Start = i + 1;
    } 
    else if(!OpenBracket && S[i] == ' ') {
      reverse(S.begin() + Start, S.begin() + i);
      Start = i + 1;
    }
  }
  reverse(S.begin() + Start, S.end());
  cout << S << '\n';
  return 0;
}