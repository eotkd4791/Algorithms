#include <iostream>
#include <cstring>
using namespace std;
char str[110];
int str_len,cnt;

int main() {
	fgets(str, 110, stdin);
	str_len = strlen(str);
	for (int i = 0; i < str_len; i++) {
		if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') cnt++;
	}
	printf("%d\n", cnt);
	return 0;
} 
