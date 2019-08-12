#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
using namespace std;

int N, M, K;
int MIN = INT_MAX;
int field[55][55];
int cpy[55][55];
typedef struct { int r; int c; int s; } rtt;
rtt arr[7];
int idx[7];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> field[i][j];
		}
	}

	int R, C, S;
	for (int i = 0; i < K; i++) {
		cin >> R >> C >> S;
		arr[i] = { R,C,S };
		idx[i] = i;
	}


	memcpy(cpy, field, sizeof(cpy));
	do {
		memcpy(field, cpy, sizeof(field));
		for (int k = 0; k < K; k++) {
			int ox = arr[idx[k]].r;
			int oy = arr[idx[k]].c;
			int os = arr[idx[k]].s;

			for (int s = 1; s <= os; s++) {
				int tmp = field[ox - s][oy - s];
				for (int i = ox - s + 1; i<=ox + s; i++) {
					field[i - 1][oy - s] = field[i][oy - s];
				}
				for (int j = oy - s + 1; j <= oy + s; j++) {
					field[ox + s][j - 1] = field[ox + s][j];
				}
				for (int i = ox + s - 1; i >= ox - s; i--) {
					field[i + 1][oy + s] = field[i][oy + s];
				}
				for (int j = oy + s - 1; j > oy - s; j--) {
					field[ox - s][j + 1] = field[ox - s][j];
				}
				field[ox - s][oy - s + 1] = tmp;
			}
		}
		for (int i = 1; i <= N; i++) {
			int sum = 0;
			for (int j = 1; j <= M; j++) {
				sum += field[i][j];
			}
			MIN = min(MIN, sum);
		}
	} while (next_permutation(idx, idx + K));
	cout << MIN;
	return 0;
}