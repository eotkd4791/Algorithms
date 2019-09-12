#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string st1;
string st2;

int arr1[100];
int arr2[100];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> st1;
	cin >> st2;
	for (int i = 0; i < st1.length(); i++) {
		int idx = st1[i] - 'a';
		arr1[idx]++;
	}
	for (int i = 0; i < st2.length(); i++) {
		int idx = st2[i] - 'a';
		arr2[idx]++;
	}
	int sum = 0;
	for (int i = 0; i < 100; i++) {
		int tmp = abs(arr1[i] - arr2[i]);
		sum += tmp;
	}
	cout << sum;
	return 0;
}
