////////////////////////////////
/*
        BOJ1924 2007³â
*/
////////////////////////////////
#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int mday[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	string eday[] = { "SUN","MON","TUE","WED","THU","FRI","SAT" };

	int m, d;
	int sum = 0;
	cin >> m >> d;

	for (int i = 1; i < m; i++) 
		sum += mday[i - 1];
	sum += d - 1;

	int tmp = (sum+1) % 7;
	cout << eday[tmp];

	return 0;
}