#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000];
int sum,tmp;

int main() {
	int T = 10;
	int num = 0; 

	for (int i = 1; i <= T; i++) {
		scanf("%d", &num);
		for (int x = 0; x < num; x++)
			scanf("%d", &arr[x]);

		for (int x = 0; x < num; x++) {
			if (x == 0 || x == 1) continue;
			tmp = min(arr[x] - arr[x - 2], min(arr[x] - arr[x - 1], min(arr[x] - arr[x + 1], arr[x] - arr[x + 2])));
			if (tmp < 0) {
				tmp = 0;
				continue;
			}
			sum += tmp;
		}
		printf("#%d %d\n", i, sum);
		sum = 0;
	}
	return 0;
}