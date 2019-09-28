#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int A, B, V, ret;
	cin >> A >> B >> V;

	int onedaybefore = V - A;

	if (onedaybefore % (A - B) == 0)
		ret = onedaybefore / (A - B) + 1;
	else
		ret = onedaybefore / (A - B) + 2;

	cout << ret;
	return 0;
}