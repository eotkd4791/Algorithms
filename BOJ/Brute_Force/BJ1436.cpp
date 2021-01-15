#include <iostream>
#include <string>
using namespace std;

int N;
int cnt;
int term_num=665;

bool is_term_num(int num) {
  int tmp = 0;
  string temp_str = to_string(num);

  for(int i=0; i<temp_str.size(); i++) {
    if(temp_str[i] == '6') {
      tmp++;
      if(tmp == 3) return true;
    }
    else tmp = 0;
  }
  return false;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  do {
    term_num++;
    if(is_term_num(term_num)) {
      cnt++;
    }
  } while(cnt!=N);
  
  cout << term_num << '\n';
  return 0;
}
// 666 1666 2666 3666 4666 5666 
// 6660 6661 6662 6663 6664 6665 6666 6667 6668 6669 
// 10666 11666 12666 13666 14666 15666 
// 16660 16661 16662 16663 16664 16665 16666 16667 16668 16669 
// 26661 12666 
