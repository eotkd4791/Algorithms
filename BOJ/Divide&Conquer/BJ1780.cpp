#include <iostream>
using namespace std;

int N;
int arr[2500][2500];
int ans[3];

void recur(int sx, int sy, int fx, int fy) {
  bool is_all_same = true;

  int init_num = arr[sx][sy];
  for(int i=sx; i<fx; i++) {
    for(int j=sy; j<fy; j++) {
      if(arr[i][j] != init_num) {
        is_all_same = false;
        break;
      }
    }
    if(!is_all_same) break;
  }

  if(is_all_same) {
    if(init_num == -1) {
      ans[0]++;
    } else if(init_num == 0) {
      ans[1]++;
    } else {
      ans[2]++;
    }
    return;
  }
  int range = fx - sx;
  int size = range / 3;

  for(int i=sx; i<sx + range; i+=size) {
    for(int j=sy; j<sy + range; j+=size) {
      recur(i, j, i + size, j + size);
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> N;
  
  for(int i=0; i<N; i++) {
    for(int j=0; j<N; j++) {
      cin >> arr[i][j];
    }
  } 
  recur(0, 0, N, N);

  cout << ans[0] << '\n' << ans[1] << '\n' << ans[2] << '\n';
  return 0;
}