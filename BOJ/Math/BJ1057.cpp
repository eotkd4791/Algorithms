
//////////////////////////////////
/*
        BOJ1057 토너먼트
                                */
//////////////////////////////////
/*
1,2 ->1
3,4 ->2
5,6 ->3
7,8 ->4
규칙을 못 찾은 문제이다.
짝수일 경우 N%2==0
홀수일 경우 N%2==1
*/
#include <iostream>
using namespace std;

int N, A, B;

int main() {
	cin >> N >> A >> B;
	int cnt = 0;
	while (A != B) {
		A = A % 2 + A / 2;
		B = B % 2 + B / 2;
		cnt++;
	}
	cout << cnt;
	return 0;
}