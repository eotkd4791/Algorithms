#include <iostream>
#include <functional>
#include <queue>
#include <vector>
using namespace std;

int N;
priority_queue<int, vector<int>, less<int>> q;
//ÃÖ¼ÒÈü = greater, ÃÖ´ëÈü = less

int main() {
	scanf("%d", &N);
	while (N--) {
		int X = 0;
		scanf("%d", &X);
		if (X == 0) {
			if (q.empty() == 1) {
				printf("0\n");
				continue;
			}
			else {
				printf("%d\n", q.top());
				q.pop();
				continue;
			}
		}
		if (X > 0) {
			q.push(X);
			continue;
		}
	}
	return 0;
}