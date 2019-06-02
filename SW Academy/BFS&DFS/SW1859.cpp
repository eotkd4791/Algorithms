////////////////////////////////////
/*
     SWEA1859 백만장자 프로젝트 
                                  */
////////////////////////////////////
#include <iostream>
using namespace std;
int arr[1000001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T,N;
	cin >> T;
	for(int t=1; t<=T; t++) {
		long long sum=0;
		cin >> N;
		for(int i=0; i<N; i++) {
			cin >> arr[i];
		}
		int MAX=N-1;
		for(int i=N-2; i>=0; i--) {
			if(arr[i]<arr[MAX]) sum+= arr[MAX]-arr[i];
			else MAX=i;
		}
		cout << "#" << t << ' ' << sum << '\n';
	}
	return 0;
}
