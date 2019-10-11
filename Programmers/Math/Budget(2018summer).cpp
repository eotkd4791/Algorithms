#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> d, int budget) {
	int answer = 0;
	sort(d.begin(), d.end());

	int tmp = 0; int dz = d.size();

	if (d[0] > budget)
		return 0;
	for (int i = 0; i < dz; i++) {
		if (tmp == budget)
			break;
		if (tmp > budget) {
			answer--;
			break;
		}
		tmp += d[i];
		answer++;
	}
	return answer;
}