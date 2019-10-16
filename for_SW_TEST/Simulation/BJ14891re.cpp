#include <iostream>
#include <algorithm>
#include <deque>
#include <cstring>
using namespace std;

int d[4];
deque<int> dq[4];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	char inp;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> inp;
			dq[i].push_back(inp-'0');
		}
	}
	
	int rtt;
	cin >> rtt;
	while(rtt--) {
		memset(d, 0, sizeof(d));
		int num; int dir;
		cin >> num >> dir;
		num--;

		if (dir == 1) 
			d[num] = 1;
		else 
			d[num] = -1;
		
		for (int left = num - 1; left >= 0; left--) {
			if (dq[left + 1].at(6) != dq[left].at(2)) 
				d[left] = d[left + 1] * (-1);
			else
				d[left] = 0;
		}

		for (int right = num + 1; right < 4; right++) {
			if (dq[right - 1].at(2) != dq[right].at(6)) 
				d[right] = d[right - 1] * (-1);
			else
				d[right] = 0;
		}


		for (int i = 0; i < 4; i++) {
			if (d[i] == 1) {
				dq[i].push_front(dq[i].back());
				dq[i].pop_back();
			}
			else if (d[i] == -1) {
				dq[i].push_back(dq[i].front());
				dq[i].pop_front();
			}
		}
	}

	int ret = 0; int two = 1;
	for (int i = 0; i < 4; i++) 
		if (dq[i].front() == 1) 
			ret += two << i;
	cout << ret;
	return 0;
}