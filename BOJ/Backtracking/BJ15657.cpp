////////////////////////////////////
/*
        BOJ15657 N°ú M (8)
                                */
///////////////////////////////////
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
int arr[10];
vector<int> v;

void recur(int idx, int cnt) {
	if (cnt == M) {
		for (vector<int> ::iterator iter = v.begin(); iter != v.end(); iter++) {
			cout << *iter << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = idx; i < N; i++) {
		v.push_back(arr[i]);
		recur(i, cnt + 1);
		v.pop_back();
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
