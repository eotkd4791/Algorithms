#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

long long ans = 1;
char str[3][7];
char resist[10][7] = { "black", "brown","red","orange","yellow","green","blue","violet","grey","white" };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 3; i++)
		cin >> str[i];

	for (int i = 0; i < 3; i++) {
		if (i == 0) {
			for (int j = 0; j < 10; j++) {

				if (strcmp(str[i], resist[j]) == 0) {
					ans = j * 10;
					break;
				}
			}
		}

		else if (i == 1) {
			for (int j = 0; j < 10; j++) {
				if (strcmp(str[i], resist[j]) == 0) {
					ans += j;
					break;
				}
			}
		}
		else {
			for (int j = 0; j < 10; j++) {
				if (strcmp(str[i], resist[j]) == 0) {
					long long tmp = (long long) pow(10, j);
					ans *= tmp;
					break;
				}
			}
		}
	}
	cout << ans;
	return 0;
}