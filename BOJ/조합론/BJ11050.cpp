#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int N,K;

int cmb(int n, int k)
{
	int tmp = 1;
	for(int i=0; i<k; i++) 
    {
		tmp *= n - i;
	}
    
	int fac = 1;
	for(int i=k; i>=1; i--) 
    {
		fac *= i;
	}
	return tmp / fac;
}

int main () 
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> N >>K;
	
	cout << cmb(N, K);
	
	return 0;
} 