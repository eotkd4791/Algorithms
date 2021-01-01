#include <iostream>
#include <map>
using namespace std;

string inputWord;
string croatian[8] = {"c=","c-","dz=","d-","lj","nj","s=","z="};
map<string, bool> mappedCroatian;
int result;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  for(int i=0; i<8; i++) mappedCroatian.insert(make_pair(croatian[i], true));

  cin >> inputWord;

  int i=0;
  string tempString;

  while(i < inputWord.size()) {
    tempString = inputWord[i];
    bool isMatch = false;

    for(int j=1; j<3; j++) {
      tempString += inputWord[i+j];
      if(mappedCroatian[tempString]) {
        isMatch = true;
        i += j + 1;
        break;
      }
    }
    if(!isMatch) i++;
    result++;
  }
  
  cout << result << '\n';
  return 0;
}