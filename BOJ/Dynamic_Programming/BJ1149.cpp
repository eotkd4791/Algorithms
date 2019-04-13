#include <iostream>
using namespace std;

int main() {
	int N, cnt = 0;
#include <iostream>
	using namespace std;

	int main() {
		int N, cnt = 0;
		int arr[11], check[11] = {};

		scanf("%d", &N);
		for (int i = 1; i <= N; i++) {
			scanf("%d", &arr[i]);
		}
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (check[j] == 0) cnt++;
				if (cnt > arr[i]) {
					check[j] = i;
					break;
				}
			}
			cnt = 0;
		}
		for (int i = 1; i <= N; i++) printf("%d ", check[i]);
		return 0;
	} 
