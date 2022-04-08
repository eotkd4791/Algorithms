#include <bits/stdc++.h>
using namespace std;

int arr[26];
string str, temp, answer;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> str;
  for(const auto& s : str) arr[s - 'A']++;

  for(int i = 2; i >= 1; i--) {
    for(int j = 0; j < 26; j++) {
      if(arr[j] > 0) {
        for(int k = 0; k < arr[j] - (arr[j] % i); k++) temp += j + 'A';
        arr[j] -= arr[j] - (arr[j] % i);
        if(answer.empty()) {
          answer = temp;
        } else {
          int half = answer.size() / 2;
          string left = answer.substr(0, half);
          string right = answer.substr(half);
          answer = left + temp + right;
        }
        temp.clear();
      }
    }
  }

  string r_answer = answer;
  reverse(answer.begin(), answer.end());
  
  if(answer != r_answer) {
    cout << "I'm Sorry Hansoo" << '\n';
    return 0;
  }
  cout << answer << '\n';
  return 0;
}