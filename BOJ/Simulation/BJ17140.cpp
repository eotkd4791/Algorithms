#include <iostream>
#include <algorithm>
#include <utility>
#include <cstring>
#include <vector>
using namespace std;

int A[101][101];
int r, c, k;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> r >> c >> k;
	r--; c--;

	int time = 0; 

	bool flag = 0; int inp;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> inp;
			A[i][j] = inp;
			if (i == r && j == c && inp == k)
				flag = 1;
		}
	}

	int row = 3; int col = 3;
	while (!flag) {

		++time;
		if (time > 100) {
			time = -1;
			break;
		}
		
		vector<pair<int, int> > v[101];

		if (row >= col) { //r연산
			for (int i = 0; i < row; i++) {
				int cnt[101] = {};
				for (int j = 0; j < col; j++) 
					cnt[A[i][j]]++;
				
				for (int j = 1; j <= 100; j++) 
					if (cnt[j] > 0) 
						v[i].push_back(make_pair(cnt[j], j));

			}

			memset(A, 0, sizeof(A));
			for (int i = 0; i < row; i++) 
				sort(v[i].begin(), v[i].end());
		
			for (int i = 0; i < row; i++) {
				int idxCol = 0;
				for (int j = 0; j < v[i].size(); j++) {
					A[i][idxCol++] = v[i][j].second;
					if (idxCol == 100)
						break;
					A[i][idxCol++] = v[i][j].first;
					if (idxCol == 100)
						break;
				}
				col = max(col, idxCol);
			}
		}

		else {//c연산
			for (int i = 0; i < col; i++) {
				int cnt[101] = {};
				for (int j = 0; j < row; j++)
					cnt[A[j][i]]++;

				for (int j = 1; j <= 100; j++)
					if (cnt[j] > 0)
						v[i].push_back(make_pair(cnt[j], j));

			}
			memset(A, 0, sizeof(A));
			for (int i = 0; i < col; i++) 
				sort(v[i].begin(), v[i].end());
			
			for (int i = 0; i < col; i++) {
				int idxRow = 0;
				for (int j = 0; j < v[i].size(); j++) {
					A[idxRow++][i] = v[i][j].second;
					if (idxRow == 100)
						break;
					A[idxRow++][i] = v[i][j].first;
					if (idxRow == 100)
						break;
				}
				row = max(row, idxRow);
			}
		}

		if (A[r][c] == k)
			flag = 1;
	}
	cout << time;
	return 0;
}