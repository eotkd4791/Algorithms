#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int N, M, D;
int arr[15][15];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M >> D;
	vector<pair<int, int> > enemy;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1)
				enemy.push_back({ i, j });
		}
	}

	vector<int> archer;
	for (int i = 0; i < M - 3; i++)
		archer.push_back(0);

	for (int i = 0; i < 3; i++)
		archer.push_back(1);

	int result = 0;
	do {
		int cnt = 0;
		vector<pair<int, int>> tmp = enemy;
		vector<int> v;
		for (int i = 0; i < archer.size(); i++)
			if (archer[i] == 1)
				v.push_back(i);

		while (!tmp.empty()) {
			vector<int> target;
			for (int i = 0; i < v.size(); i++) {//v´Â ±Ã¼ö À§Ä¡
				int idx = 0;
				int enemyY = tmp[0].second;//ÀûÀÇ yÁÂÇ¥
				int dist = abs(N - tmp[0].first) + abs(v[i] - tmp[0].second);

				for (int j = 1; j < tmp.size(); j++) {
					int tmpDist = abs(N - tmp[j].first) + abs(v[i] - tmp[j].second);
					if (dist > tmpDist) {
						enemyY = tmp[j].second;
						dist = tmpDist;
						idx = j;
					}
					else if (dist == tmpDist && enemyY > tmp[j].second) {
						enemyY = tmp[j].second;
						idx = j;
					}
				}
				if (dist <= D)
					target.push_back(idx);
			}

			target.erase(unique(target.begin(), target.end()), target.end());
			sort(target.begin(), target.end());
			int shoot = 0;
			for (int i = 0; i < target.size(); i++) {
				tmp.erase(tmp.begin() + (target[i] - shoot++));
				cnt++;
			}

			vector<pair<int, int>> cpy;
			for (int i = 0; i < tmp.size(); i++)
				if (tmp[i].first < N - 1)
					cpy.push_back({ tmp[i].first + 1, tmp[i].second });
			tmp = cpy;
		}

		result = max(result, cnt);
	} while (next_permutation(archer.begin(), archer.end()));

	cout << result << '\n';
	return 0;
}
