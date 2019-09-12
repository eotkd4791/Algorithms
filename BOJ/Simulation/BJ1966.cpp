#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

typedef struct {
	int val;
	int idx;
}pp;

int C, N, M;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> C;
	while (C--) {
		deque<pp> d;
		cin >> N >> M;

		int tmp = 0;
		int arr[101] = {};
		for (int i = 0; i < N; i++) {
			cin >> tmp;
			arr[i] = tmp;
			d.push_back({ tmp,i });
		}
		tmp = N - 1; int cnt = 0;
		sort(arr, arr + N);
		while (!d.empty()) {
			int oval = d.front().val;
			int oidx = d.front().idx;
			if (arr[tmp] == d.front().val) {
				cnt++;
				if (d.front().idx == M) {
					break;
				}
				tmp--;
			}
			else {
				d.push_back({ oval,oidx });
			}
			d.pop_front();

		}
		cout << N - 1 - tmp << '\n';
	}
	return 0;
}