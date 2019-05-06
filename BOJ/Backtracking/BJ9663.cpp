/////////////////////////////////////
/*
        BOJ9663 N-Queen 

////////////////////////////////////
*/
#include <iostream>
using namespace std;

int n;
int cnt;
bool check1[15];
bool check2[33];
bool check3[33];

void queen(int num) {
	if(num==n) {
		cnt++;
		return;
	}
	else {
		for(int i=0; i<n; i++) {
			if(check1[i] || check2[i+num] || check3[i-num+n-1])
				continue;
			check1[i]=1;
			check2[i+num]=1;
			check3[i-num+n-1]=1;
			queen(num+1);
			check1[i]=0;
			check2[i+num]=0;
			check3[i-num+n-1]=0;
			
		}
	}
}

int main () {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	queen(0);
	cout << cnt;
	return 0;
}
