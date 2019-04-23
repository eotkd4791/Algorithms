#include <iostream>
#include <cstring>
using namespace std;
char word[101];
int alp[27];

int main() {
	scanf("%s", word);
	int len = strlen(word);

	for (int i = 0; i < len; i++) {
		alp[word[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++) {
		printf("%d ",alp[i]);
	}
	return 0;
} 
