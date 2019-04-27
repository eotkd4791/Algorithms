/*갈색 타일과 빨간 타일의 관계를 파악하고 조건을 만들어 무한루프를 돌렸다.
처음에 R+B의 약수를 구하다가 안되서 R의 약수로만 생각해서 풀게되었다.
printf의 순서를 바꾸면 틀렸다고 나오는데 왜 그러는지 모르겠다.*/
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int R, B = 0; //B=(L-2)(W-2),  B=wl  //R=2(W+L)-4,  R=2(w+l)+4
	int l = 1;	//l,w != 1,2 
	int w = 1;  //l=L-2, w=W-2
	
	scanf("%d%d", &R, &B);
	while (1) {
		if (B % l == 0) {
			w = B / l;
			if (R == 2 * (l + w) + 4) {
				printf("%d %d\n", w + 2, l + 2);
				break;
			}
		}
		l++;
	}
	return 0; 
}
