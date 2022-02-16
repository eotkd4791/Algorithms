#include <iostream>
#include <algorithm>
using namespace std;

int N, Answer;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for(int i=0; i<=N; i++) {
    for(int j=0; j<60; j++) {
      for(int k=0; k<60; k++) {
        if(to_string(i).find('3') != string::npos
        || to_string(j).find('3') != string::npos
        || to_string(k).find('3') != string::npos
        ) {
          Answer++;
        }
      }
    }
  }
  cout << Answer<< '\n';
}