#include <iostream>
#include <string>
using namespace std;

string dial;
int sec[26]={ 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 10, 10, 10, 10 };
int sum;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> dial;

  for(int i=0; i<dial.size(); i++) {
    int index = dial[i] - 'A';
    sum += sec[index];
  }
  cout << sum << '\n';
  return 0;
}
