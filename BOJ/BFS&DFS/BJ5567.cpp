//////////////////////////////////////
/*
           BOJ5567 °áÈ¥½Ä
                                    */
//////////////////////////////////////

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int cnt;
bool check[10001];
vector<vector<int> > v(10001);
queue<int> q;
int sum;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	cin >> m;

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	 }

	for (int i = 0; i < v[1].size(); i++) {
		int tmp = v[1][i];
		q.push(tmp);
	}

	while (!q.empty()) {
		int oq = q.front();
		check[oq] = 1;
		q.pop();
		for (int n = 0; n < v[oq].size(); n++) {
			int idx = v[oq][n];
			check[idx] = 1;
		}
	}

	for (int i = 2; i <= n; i++) {
		if (check[i] == true) {
			sum++;
		}
	}

	cout << sum;
	return 0;
}