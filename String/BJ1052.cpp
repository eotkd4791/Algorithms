/*문자열 맨뒤에는 NULL문자가 온다는 것을 기억하자.
맨앞이 빈칸이면 0으로 시작해서 빈칸의 수 cnt를 올렸다.
맨앞이 문자면 1로 시작해서 cnt 를 올렸고, 
맨뒤가 빈칸이면 끝에서 cnt를 하나 감소시켰다.
str[str_len-1]에는 NULL문자가 포함되어있다.*/
#include <iostream>
#include <cstring>
using namespace std;
char str[1000001];
int str_len, cnt=1;

int main() {
	fgets(str, 1000001, stdin);
	str_len = strlen(str);
	if (str[0] == ' ') cnt = 0;
	for (int i = 0; i < str_len; i++) {
		if (str[i] == ' ') cnt++;
	}
	if (str[str_len - 2] == ' ') cnt--;
	printf("%d", cnt);
	return 0;
}