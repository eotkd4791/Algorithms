#include <iostream>
#include <cstring>
using namespace std;
char str[105];

int main() {
	fgets(str, 105, stdin);
	printf("%c", str[0]);
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == '-') printf("%c", str[i+1]);
	}
	return 0;
}