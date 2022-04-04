#include <bits/stdc++.h>
using namespace std;

string word;
int answer = 1;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> word;

  int size = (int) word.size();
  for(int i = 0; i < size; i++) {
    int left = i;
    int right = size - 1 - i;
    if(left == right) {
      answer = 1;
      break;
    }
    if(word[left] != word[right]) {
      answer = 0;
      break;
    }
  }
  cout << answer << '\n';
  return 0;
}