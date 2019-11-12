#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, a, b = 0;
	pair<int, int> arr[100001] = {};
	
	cin >> N;
	for (int i = 0; i < N; i++) 
	{
		cin >> a >> b;
		arr[i] = make_pair(b, a); //first ≥° second Ω√¿€
	}

	sort(arr, arr + N); 

	int ans = 1; int end = arr[0].first;
	for (int i = 1; i < N; i++)
	{
		if (arr[i].second >= end) 
		{
			ans++;
			end = arr[i].first;
		}
	}
	cout << ans;
	return 0;
}