#include <iostream>
using namespace std;
int T[1001];

bool Erk(int sum) {
	for (int i = 1; T[ i] < sum; i++) {
		for (int j = 1; T[j] < sum; j++) {
			for (int k = 1; T[k] < sum; k++) {
				if (T[i] + T[j] + T[k] == sum) return true;
				
			}
		}
	}
	return false;
}
int main() {
	int t, k = 0;

	for (int i = 1; i <= 1001; i++) {
		T[i] = (i*(i + 1)) / 2;
	}

	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		scanf("%d", &k);
		printf("%d\n", Erk(k));
	}
	
	return 0;
}