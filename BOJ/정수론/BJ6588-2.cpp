#include <iostream>
#include <cmath>
using namespace std;

const int INF = 1000000;
const string NOT_EXIST = "Goldbach's conjecture is wrong.";
bool NotPrimes[INF + 1];
int N;

void CreatePrime() {
  NotPrimes[1] = NotPrimes[INF] = true;
  for(int i=2; i<=sqrt(INF); i++) {
    if(!NotPrimes[i]) {
      for(int j=i+i; j<=INF; j+=i) {
        NotPrimes[j] = true;
      }
    }
  }
  NotPrimes[2] = true;
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  CreatePrime();

  while(1) {
    cin >> N;
    if(N == 0) {
      break;
    }
    int A=0; 
    int B=0; 
    int Diff=0;

    for(int i=N; i>2; i--) {
      int TempA = N - i;
      int TempB = i;

      if(!NotPrimes[TempA] && !NotPrimes[TempB]) {
        if(Diff <= abs(TempA - TempB)) {
          Diff = abs(TempA - TempB);
          A = TempA;
          B = TempB;
          break;
        }
      }
    }

    if(A > 0 && B > 0) {
      cout << N << " = " << A << " + " << B << '\n';
    }
    else {
      cout << NOT_EXIST << '\n';
    }
  }
  return 0;
}