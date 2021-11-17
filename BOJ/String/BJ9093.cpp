#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int T;
string Words;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;
  cin.ignore();
  while(T--) {
    getline(cin, Words);

    int Start = 0;
    for(int i=0; i<Words.size(); i++) {
      if(Words[i] == ' ') {
        reverse(Words.begin() + Start, Words.begin() + i);
        Start = i + 1;
      }
    }
    reverse(Words.begin() + Start, Words.end());
    cout << Words << '\n';
  }
  return 0;
}