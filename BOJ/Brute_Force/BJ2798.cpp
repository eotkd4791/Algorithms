#include <iostream>
using namespace std;

int N;
int M;
int card[101];
int MAX;

void black_jack(bool check[101], int idx, int cnt, int sum) {
  
  if(cnt == 3) {
    if(sum <= M) MAX = MAX < sum ? sum : MAX;
    return;
  }

  for(int i=idx + 1; i<N; i++) {
    if(check[i]) continue;
    check[i] = true;
    black_jack(check, i, cnt + 1, sum + card[i]);
    check[i] = false;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;
  for(int i=0; i<N; i++)
    cin >> card[i];


  bool check[101]={};

  black_jack(check, 0, 0, 0);
  cout << MAX << '\n';
  return 0;
}