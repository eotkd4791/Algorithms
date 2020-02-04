#include <iostream>
#define endl '\n'
using namespace std;

int N, M, arr[10001];
int j, sum, cnt;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) 
		cin >> arr[i];

	for (int i = 0; i < N; i++) {
		j = i;
		sum = 0;
		while (j < N) {
			sum += arr[j];
			if (sum == M) {
				cnt++;
				break;
			}
			else if (sum > M) 
				break;
			j++;
		}
	}
	cout << cnt << endl;
	return 0;
}