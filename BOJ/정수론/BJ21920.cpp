#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

const int LIMIT = 500001;
int N, X;
int Nums[LIMIT];
vector<int> List;

int GCD(int a, int b) {
  if(b == 0) return a;
  return GCD(b, a % b);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> N;
  for(int i=0; i<N; i++) {
    cin >> Nums[i];
  }
  cin >> X;

  for(int i=0; i<N; i++) {
    if(GCD(Nums[i], X) == 1) {
      List.push_back(Nums[i]);
    }
  }

  double Sum = 0;
  double Count = (int) List.size();

  for(auto const& Num : List) {
    Sum += Num;
  }
  cout << Sum / Count << '\n';
  return 0;
}