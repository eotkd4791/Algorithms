#include <iostream>
#include <string>

using namespace std;

string str;
int arr[30];
int MAX;
int res;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> str;

  for (int i = 0; i < str.size(); i++) {
    int idx;

    if ('a' <= str[i] && str[i] <= 'z') 
      idx = str[i] - 'a';
    else
      idx = str[i] - 'A';

    arr[idx]++;

    if (MAX < arr[idx]) {
      MAX = arr[idx];
      res = idx;
    }
  }
  for (int i = 0; i < 26; i++) {
    if (MAX == arr[i] && res != i) {
      cout << '?' << '\n';
      return 0;
    }
  }
  cout << (char) ('A' + res) << '\n';
  return 0;
}