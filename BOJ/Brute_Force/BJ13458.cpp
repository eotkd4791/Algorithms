#include <iostream>
#include <algorithm>
#define INF 1000000
using namespace std;

int N, B, C;
int A[INF + 1];


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	cin >> B >> C;

	long long sum = N;
	for (int i = 0; i < N; i++) {
		A[i] -= B;
		if (A[i] > 0) {
			int div = A[i] / C;
			int mod = A[i] % C;
			sum += div;
			if (mod > 0)
				sum++;
		}
	}
	cout << sum;
	return 0;
}