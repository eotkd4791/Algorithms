#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

string S;
vector<string> Suffixes;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> S;
  for(int i=0; i<S.size(); i++) {
    string temp="";
    for(int j=i; j<S.size(); j++) {
      temp += S[j];
    }
    Suffixes.push_back(temp);
  }

  sort(Suffixes.begin(), Suffixes.end());

  for(const auto& Suffix : Suffixes) {
    cout << Suffix << '\n';
  }
  return 0;
}