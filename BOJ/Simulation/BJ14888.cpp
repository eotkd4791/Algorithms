//////////////////////////////
/*
   BOJ14888 연산자 끼워넣기
                            */
//////////////////////////////
//최소값 최대값이 (-)로 나올 수 있는
//경우의 수까지 뿌사버렸다.

#include <iostream>
#include <algorithm>
#define INF 1000000000
#define mINF -1000000000
using namespace std;

int n;
int a[12];
int o[4]; // [0]+ [1]- [2]* [3]/
int b[12];
int MIN=INF, MAX= mINF;
int ii;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) 
		cin >> a[i];

	for (int i = 0; i < 4; i++) {
		cin >> o[i];
		while (o[i]--) {
			b[ii++] = i;
		}
	}
	
	
	do {
		int sum = a[0];
		for (int i = 1; i < n; i++) {
			if (b[i-1] == 0) {//+
				sum += a[i];
			}
			else if (b[i-1] == 1) {//-
				sum -= a[i];
			}
			else if (b[i-1] == 2) {//*
				sum *= a[i];
			}
			else if (b[i-1] == 3) {// /
				sum /= a[i];
			}
		}
		MAX = max(MAX, sum);
		MIN = min(MIN, sum);
	} while (next_permutation(b,b+n-1));

	cout << MAX << "\n" << MIN;
	return 0;
}