/*입력 받은 배열의 값이 0인 부분까지 cnt를 세서 값이 이상하게 나왔다.
찾느라 고생했다. 이중 for문의 조건식을 0이 아닐때만 
돌게 바꿔서 올바른 값을 출력해 냈다. 
그리고 배열 선언할때 메모리를 여유있게 선언해야겠다.
15로 선언해서 틀렸다.
이번 문제도 실수.*/
#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int arr[16] = {};
	int cnt = 0;
	int i = 0;

	while (1) {
		for (i = 0; i < 16; i++) {
			scanf("%d", &arr[i]);
			if (arr[i] == 0 || arr[i] == -1) break;		//for문 탈출
		}
		if (arr[i] == -1) break;						//무한루프 탈출

		if (arr[i] == 0) {								//0일때 리스트가 초기화됨.
			for (int k = 0; arr[k] != 0; k++) {			
				for (int j = 0; arr[j] != 0; j++) {
					if (arr[j] == arr[k] * 2) {
						cnt++;
						break;
					}
				}
			}
			printf("%d\n", cnt);
			cnt = 0;
			memset(arr, 0, sizeof(arr));			//배열, cnt, i값 초기화
			
		}
	}
	return 0;
