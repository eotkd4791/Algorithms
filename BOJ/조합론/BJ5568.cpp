#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n,k;
string arr[11];
bool check[11];
vector<int> v;


void recur(int idx, int cnt, string str) {
	if(cnt == k) {
		v.push_back(atoi(str.c_str()));
		return;
	}
	for(int i=0; i<n; i++) {
		if(check[i]) continue;
		check[i]=true;
		recur(i+1, cnt + 1, str + arr[i]);
		check[i] = false;
	}
}

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	 
	cin >> n >> k;
	for(int i=0; i<n; i++) 
		cin >> arr[i];
	
	sort(arr,arr+n);
	
	string str;
	recur(0, 0, str);
	
	sort(v.begin(),v.end());
	
	v.erase(unique(v.begin(),v.end()),v.end());
	
	cout << v.size(); 
	
//	cout << endl;
//	for(int i=0; i<v.size(); i++) {
//		cout << v[i] << ' ';
//	}
	return 0;
} 