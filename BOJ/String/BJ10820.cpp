#include <iostream>
#include <string>
using namespace std;

string Input;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  while(getline(cin, Input)) {
    int Lower = 0;
    int Upper = 0;
    int Space = 0;
    int Number = 0;
    for(int i=0; i<Input.size(); i++) {
      if('a' <= Input[i] && Input[i] <= 'z') {
        Lower++;
      }
      else if('A' <= Input[i] && Input[i] <= 'Z') {
        Upper++;
      }
      else if('0' <= Input[i] && Input[i] <= '9') {
        Number++;
      }
      else if(Input[i] == ' ') {
        Space++;
      }
    }
    cout << Lower << ' ' << Upper << ' ' << Number << ' ' << Space << '\n';
  }
  return 0;
}