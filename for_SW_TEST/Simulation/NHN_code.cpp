#include <iostream>
#include <deque>
#include <cmath>
using namespace std;

int N, W;
string field[101][101];
deque<string> dq[51];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> W;
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) 
			cin >> field[i][j];
		
	int round = 0; int dir = 1;
	int st = 0, end = N;
	if (W < 0) dir *= -1;

	while (round < N / 2) {
		for (int j = st; j < end; j++) 
			dq[round].push_back(field[st][j]);
		
		for (int i = st + 1; i < end; i++) 
			dq[round].push_back(field[i][end - 1]);
		
		for (int j = end - 2; j >= st; j--) 
			dq[round].push_back(field[end - 1][j]);
		
		for (int i = end - 2; i > st; i--) 
			dq[round].push_back(field[i][st]);
		
		st++;
		end--;
		round++;
	}

	int cyc = abs(W); 
	st = 0; end = N;
	round = 0;

	while (round < N / 2) {
		int len = cyc % ((end - 1) * 4);
		if (dir > 0) {//시계
			while (len--) {
				string tmp = dq[round].back();
				dq[round].push_front(tmp);
				dq[round].pop_back();
			}
			dir *= -1;
		}
		else {//반시계
			while (len--) {
				string tmp = dq[round].front();
				dq[round].push_back(tmp);
				dq[round].pop_front();
			}
			dir *= -1;
		}
		end -= 2;//***한 변을 기준으로 보면 회전 시킬 이름의 갯수가 2씩 줄어든다.
		round++;
	}

	round = 0; st = 0; end = N;

	while (round < N / 2) {
		for (int j = st; j < end; j++) {
			field[st][j] = dq[round].front();
			dq[round].pop_front();
		}
		for (int i = st + 1; i < end; i++) {
			field[i][end - 1] = dq[round].front();
			dq[round].pop_front();
		}
		for (int j = end - 2; j >= st; j--) {
			field[end - 1][j] = dq[round].front();
			dq[round].pop_front();
		}
		for (int i = end - 2; i > st; i--) {
			field[i][st] = dq[round].front();
			dq[round].pop_front();
		}
		st++; end--;
		round++; 
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << field[i][j];
			if (j == N - 1) cout << '\n';
			else cout << ' ';
		}
		cout << '\n';
	}
	return 0;
}