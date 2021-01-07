#include <iostream>
#include <string>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  string a, b, res;

  cin >> a >> b;

  int alen = (int) a.size();
  int blen = (int) b.size();

  int len_diff = alen-blen;
  int is_a_big = -1;

  if(len_diff > 0) is_a_big = 1;
  else if(len_diff < 0) {
    is_a_big = 0;
    len_diff *= (-1);
  }

  if(is_a_big >= 0)  {
    for(int i=0; i<len_diff; i++) {
      if(is_a_big) b = '0' + b;
      else  a = '0' + a;
    }
  }
  int mlen = alen > blen ? alen : blen;

  bool is_over_ten = false;

  for(int i=mlen; i>=0; i--) {
    int a_num = a[i]-'0';
    int b_num = b[i]-'0';  

    int sum = a_num + b_num;

    if(is_over_ten) {
      sum++;
      is_over_ten = false;
    }
    if(sum >= 10) {
      is_over_ten = true;
      sum -= 10;
    }
    res = (char) ('0' + sum) + res;
  }
  
  if(is_over_ten) res = '1' + res;
  res = res.substr(0, res.size() -1);

  cout << res << '\n';
  return 0;
}