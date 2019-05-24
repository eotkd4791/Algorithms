/////////////////////////////////
/*
        BOJ15655 N과 M (6)
                               */
/////////////////////////////////
#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[10];
bool check[10];

void recur(int idx, int cnt) {
	if (cnt == M) {
		for (int i = 0; i < N; i++) {
			if (check[i]) {
				cout << arr[i] << ' ';
			}
		}
		cout << '\n';
	}
	for (int i = idx; i < N; i++) {
		if (!check[i]) {
			check[i] = 1;
			recur(i + 1, cnt + 1);
			check[i] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	recur(0,0);
	return 0;
} 
  
