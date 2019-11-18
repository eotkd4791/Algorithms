#include <iostream>
#include <vector>
using namespace std;

int N, M, c, a, b;
vector<int> parent, level;

int search(int u) {
	if (parent[u] == u) return u;
	return parent[u] = search(parent[u]);
}

void merge(int u, int v) {
	int ru = search(u); int rv = search(v); //root ±¸ÇÏ±â
	if (ru == rv) return;

	if (level[ru] > level[rv])  /
		parent[rv] = ru;

	else if (level[ru] < level[rv])
		parent[ru] = rv;

	else
	{
		parent[ru] = rv;
		level[ru]++;
	}
}

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int n = 0; n <= N; n++) {
		parent.push_back(n);
		level.push_back(1);
	}
	
	for (int m = 0; m < M; m++)
	{
		cin >> c >> a >> b;
		if (c==0) //Union
			merge(a, b);
		
		else	  //Find
		{
			if (search(a) == search(b))
				cout << "YES" << '\n';
			else
				cout << "NO" << '\n';
		}
	}
	return 0;
}