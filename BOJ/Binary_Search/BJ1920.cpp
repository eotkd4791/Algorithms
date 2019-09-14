#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M = 0;
	int A[100001] = {};

	cin >> N;
	for (int i = 1; i <= N; i++) 
		cin >> A[i];
	sort(A + 1, A + N + 1);

	cin >> M;
	int tmp = 0;
	for (int j = 1; j <= M; j++) {
		cin >> tmp;
		cout << binary_search(A + 1, A + N + 1, tmp) << '\n';
	}
	return 0;
}