#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;

const int MAX_LEN = 10001;
const int MAX_NUM = 1000001;

int N;
int Nums[MAX_LEN];
bool Primes[MAX_NUM];
unsigned long long Answer = 1;
set<int> Set;

void GetPrimes() {
  fill(Primes, Primes + MAX_NUM, true);

  for(int i=2; i<=sqrt(MAX_NUM); i++) {
    if(Primes[i]) {
      for(int j=i*i; j<=MAX_NUM; j+=i) {
        Primes[j] = false;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  GetPrimes();

  cin >> N;
  for(int i=0; i<N; i++) {
    cin >> Nums[i];
    if(Primes[Nums[i]]) {
      Set.insert(Nums[i]);
    }
  }

  if(Set.empty()) {
    cout << -1 << '\n';
    return 0;
  }
  
  for(auto & Num : Set) {
    Answer *= Num;
  }
  cout << Answer << '\n';
  return 0;
}