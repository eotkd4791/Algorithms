#include <iostream>
using namespace std;

const int INF = 100000 + 1;
int G, P, a, cnt;
bool flag;
int parent[INF];

int find(int v)
{
	if (v == parent[v])
		return v;
	return parent[v] = find(parent[v]);
}

void merge(int u, int v)
{
	int ru = find(u);
	int rv = find(v);
	parent[u] = v;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> G;
	for (int g = 1; g <= G; g++)
		parent[g] = g;
	cin >> P;

	for (int i = 0; i < P; i++)
	{
		cin >> a;
		if (flag)
			continue;

		int tmp = find(a);
		if (tmp != 0)
		{
			merge(tmp, tmp - 1);
			cnt++;
		}
		else
			flag = true;
	}
	cout << cnt << '\n';
	return 0;
}