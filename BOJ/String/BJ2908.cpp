#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string num1;
string num2;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> num1 >> num2;
    
  reverse(num1.begin(), num1.end());
  reverse(num2.begin(), num2.end());

  for(int i=0; i<3; i++) {
    if(num1[i] > num2[i]) {
      cout << num1 << '\n';
      break;
    }
    else if(num1[i] < num2[i]) {
      cout << num2 << '\n';
      break;
    }
  }
  return 0;
}
