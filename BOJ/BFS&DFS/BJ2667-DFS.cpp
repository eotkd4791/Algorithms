/*scanf로 입력 받을 때, 띄어쓰기나 줄바꿈 없이 입력을 받기 때문에
"%1d"형태로 입력을 받았다.
cnt는 총 단지 수, ans는 각 단지마다 가구수를 뜻함.
ans를 result배열에 저장하여 값을 출력하였다.
ans은 탐색을 시작하면서 카운트를 해야 올바른 값이 나온다. 그래서
1로 초기화를 했다.
*/
#include <iostream>
#include <algorithm>
using namespace std;
int N, field[30][30], check[30][30], cnt, ans=1, result[9000];
int dr[4] = { 0,0,1,-1 };
int dc[4] = { -1,1,0,0 };

void DFS(int x, int y) {
	check[x][y] = 1;
	for (int n = 0; n < 4; n++) {
		int rx = x + dr[n];
		int cy = y + dc[n];
		if (rx >= 0 && cy >= 0 && rx < N && cy < N && check[rx][cy] == 0 && field[rx][cy] == 1) {
			check[rx][cy] = 1;
			DFS(rx, cy);
			ans++;
		}
	}

}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1d", &field[i][j]);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (check[i][j] == 0 && field[i][j] == 1) {
				DFS(i, j);
				result[cnt] = ans;
				cnt++;
				ans = 1;
				
			}
		}
	}
	printf("%d\n", cnt);
	sort(result, result + cnt);
	for (int k = 0; k < cnt; k++) {
		printf("%d\n", result[k]);
	}
	return 0;
}