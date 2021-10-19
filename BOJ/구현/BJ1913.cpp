#include <iostream>
using namespace std;

int N, P;
int arr[1001][1001];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> P;

  int num = 1;
  int step = 0;
  int x = N / 2;
  int y = N / 2;

  arr[x][y] = 1;

  while(step < N) {
    step++;
    for(int i=1; i<=step; i++) {
      arr[x--][y] = num++;
    }

    if(step >= N) break;

    for(int i=1; i<=step; i++) {
      arr[x][y++] = num++;
    }

    step++;

    for(int i=1; i<=step; i++) {
      arr[x++][y] = num++;
    }

    for(int i=1; i<=step; i++) {
      arr[x][y--] = num++;
    }
  }

  int px = 0;
  int py = 0;
  for(int i=0; i<N; i++) {
    for(int j=0; j<N; j++) {
      if(P == arr[i][j]) {
        px = i + 1;
        py = j + 1;
      }
      cout << arr[i][j] << ' ';
    }
    cout << '\n';
  }
  cout << px << ' ' << py << '\n';
  return 0;
}