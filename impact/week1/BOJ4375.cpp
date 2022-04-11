#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
  while(scanf("%d", &n) != EOF) {
    int cnt = 1;
    int num = 1;
    while(true) {
      if(cnt % n == 0) {
        printf("%d\n", num);
        break;
      } else {
        cnt = cnt * 10 + 1;
        cnt %= n;
        num++;
      }
    }
  }
  return 0;
}