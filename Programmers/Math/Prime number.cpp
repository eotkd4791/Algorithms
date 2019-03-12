/*
 ========================
   Programmers - 소수찾기
 ========================

+++++++++++++++++++++++++
'에라토스테네스의 체'를 이용하여
 구현하였다.
+++++++++++++++++++++++++
 */

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
	int arr[n + 3];
	int cnt = 0;//초기화
	for (int i = 2; i <= n; i++) {
		arr[i] = i;
	}//배열을 가장 작은 소수인 2부터 입력 받는 수 n까지 채운다
	for (int i = 2; i*i <= n; i++) {//n까지 다 볼 필요없이 i<=sqrt(n)까지만 본다.
		/*예를들어, n==100
		 1*100
		 2*50
		 4*25
		 5*20
		 10*10
		 20*5
		 25*4
		 50*2
		 100*1   중복되기 때문에 볼 필요x
		 */
		if (arr[i] == 0) continue;
		for (int j = i * 2; j <= n; j += i) {//배수 제거
			arr[j] = 0;
		}
	}
	for (int k = 2; k <= n; k++) {
		if (arr[k] != 0) cnt++;
	}
	return cnt;
}