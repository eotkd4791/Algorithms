#include <bits/stdc++.h>
using namespace std;

int mom1 ,mom2, son1, son2;

int gcd(int a, int b) {
	if(b==0) return a;
	return gcd(b, a%b);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> son1 >> mom1;
	cin >> son2 >> mom2;
	
	int under = mom1 * mom2;
	int top = mom1 * son2 + mom2 * son1;
	
	int tmp = gcd(top, under);
	cout << top / tmp << ' ' << under / tmp;
	return 0;	
}