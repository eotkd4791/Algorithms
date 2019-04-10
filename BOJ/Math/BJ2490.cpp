#include <iostream>
#include <algorithm>
using namespace std;
int arr[4],cnt;

int main() {
	for (int j = 1; j <= 3; j++) {
		for (int i = 0; i < 4; i++) {
			scanf("%d", &arr[i]);
		}
		for (int i = 0; i < 4; i++) {
			if (arr[i] == 1) cnt++;
		}
		if (cnt == 4) printf("E\n");
		if (cnt == 3) printf("A\n");
		if (cnt == 2) printf("B\n");
		if (cnt == 1) printf("C\n");
		if (cnt == 0) printf("D\n");
		cnt = 0;
		for (int i = 0; i < 4; i++) {
			arr[i] = 0;
		}
	}
	return 0;
} 
