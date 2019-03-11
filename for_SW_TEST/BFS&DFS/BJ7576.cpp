#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int N, M, ground[1005][1005], growth[1005][1005];
int day;
queue<pair<int, int> > q;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void BFS() {
	int round = growth[q.front().first][q.front().second];
	while (!q.empty()) {
		int xtoday = q.front().first;
		int ytoday = q.front().second;
		q.pop();

		if (growth[xtoday][ytoday] > round) {
			day++;
			round++;
		}
		for (int n = 0; n < 4; n++) {
			int xafter = xtoday + dx[n];
			int yafter = ytoday + dy[n];

			if (xafter >= 0 && yafter >= 0 && xafter < N && yafter < M && ground[xafter][yafter] == 0 && growth[xafter][yafter] == 0) {
				growth[xafter][yafter] = day + 1;
				ground[xafter][yafter] = ground[xtoday][ytoday];
				q.push({ xafter,yafter });
			}
		}
	}
}

int main() {
	scanf("%d%d", &M, &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &ground[i][j]);
			if (ground[i][j] == 1) {
				q.push(make_pair(i, j));
			}
		}
	}
	BFS();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (ground[i][j] == 0) day = -1;
		}
	}
	printf("%d\n", day);
	return 0;
}