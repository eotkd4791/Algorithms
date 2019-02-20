<<<<<<< HEAD
/*BOJ 1926 ±×¸²
BFS¸¦ ÀÌ¿ëÇÑ Flood fill¹®Á¦
queue¿¡¼­ popÀÌ µÉ ¶§¸¶´Ù sumÀ» ´õÇÏ°í MAX°ªÀ» °»½ÅÇß´Ù.
queueÃÊ±âÈ­¿¡ ½Å°æ½è´Âµ¥ »ç½Ç»ó while¹®À»
Å»ÃâÇÏ·Á¸é queue°¡ ºñ¾îÀÖ¾î¾ß ÇÏ´Ï±î...
¶Ç field¿¡¼­ 0ÀÎ ºÎºÐÀ» µé¾î°¡Áö ¾Ê±â À§ÇØ¼­ Á¶°ÇÀ» µû·Î Ãß°¡Çß´Ù.*/
=======
/*BOJ 1926 ê·¸ë¦¼
BFSë¥¼ ì´ìš©í•œ Flood fillë¬¸ì œ
queueì—ì„œ popì´ ë  ë•Œë§ˆë‹¤ sumì„ ë”í•˜ê³  MAXê°’ì„ ê°±ì‹ í–ˆë‹¤.
queueì´ˆê¸°í™”ì— ì‹ ê²½ì¼ëŠ”ë° ì‚¬ì‹¤ìƒ whileë¬¸ì„
íƒˆì¶œí•˜ë ¤ë©´ queueê°€ ë¹„ì–´ìžˆì–´ì•¼ í•˜ë‹ˆê¹Œ...
ë˜ fieldì—ì„œ 0ì¸ ë¶€ë¶„ì„ ë“¤ì–´ê°€ì§€ ì•Šê¸° ìœ„í•´ì„œ ì¡°ê±´ì„ ë”°ë¡œ ì¶”ê°€í–ˆë‹¤.*/

>>>>>>> 3754c4c0ff2c90cf5794517c9e619507d41dd233
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
int N, M;
int field[510][510];
int cnt;
int check[510][510];
int sum, MAX;
int dr[4] = { 0,0,1,-1 };
int dc[4] = { -1,1,0,0 };

void BFS(int x, int y) {
	queue <pair<int, int>> q = {};
	check[x][y] = 1;
	q.push({ x,y });
	while (q.empty() == 0) {
		int xnow = q.front().first;
		int ynow = q.front().second;
		q.pop();
		sum++;
		for (int n = 0; n < 4; n++) {
			int rx = xnow + dr[n];
			int cy = ynow + dc[n];
			if (rx >= 0 && cy >= 0 && rx < N && cy < M && check[rx][cy] == 0 && field[rx][cy] != 0) {
				check[rx][cy] = 1;
				q.push({ rx,cy });
			}
		}
	}
	MAX = max(MAX, sum);
	sum = 0;
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &field[i][j]);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (check[i][j] == 0 && field[i][j] == 1) {
				BFS(i, j);
				cnt++;
			}
		}
	}
	printf("%d\n%d\n", cnt, MAX);
	return 0;
}
