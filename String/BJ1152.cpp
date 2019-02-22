#include <iostream>
#include <cstring>
using namespace std;
char str[1000000];
int str_len,cnt;

int main() {
	fgets(str, 1000000, stdin);
	str_len = strlen(str);
	for (int i = 0; i < str_len; i++) {
		if (str[i] == ' ') cnt++;
	}
	printf("%d", cnt+1);
	return 0;
}